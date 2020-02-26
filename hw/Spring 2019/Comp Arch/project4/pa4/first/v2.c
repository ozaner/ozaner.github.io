#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Global Variables
int miss;
int hit;
int mr;
struct line** cache;
unsigned long int count;
int mw;

// Line Struct
typedef struct line {
  unsigned long int tag;
  int valid;
  unsigned long int time;
} line;

// Function Declarations
void readsim(unsigned long int tagindex,unsigned long int setindex,int assoc);
line** createcache(int setnum,int assoc);
void writesim(unsigned long int tagindex,unsigned long int setindex,int assoc);
void empty(int setnum, int assoc);
void prefetchww(unsigned long int tagindex,unsigned long int setindex,int assoc);
void prefetchrr(unsigned long int tagindex,unsigned long int setindex,int assoc);
void prefetchr(unsigned long int tagindex,unsigned long int setindex,int assoc,unsigned long int tagindexn,unsigned long int setindexn);
void prefetchw(unsigned long int tagindex,unsigned long int setindex,int assoc,unsigned long int tagindexn,unsigned long int setindexn);
void readsiml(unsigned long int tagindex,unsigned long int setindex,int assoc);
void writesiml(unsigned long int tagindex,unsigned long int setindex,int assoc);
void prefetchwwl(unsigned long int tagindex,unsigned long int setindex,int assoc);
void prefetchrrl(unsigned long int tagindex,unsigned long int setindex,int assoc);
void prefetchrl(unsigned long int tagindex,unsigned long int setindex,int assoc,unsigned long int tagindexn,unsigned long int setindexn);
void prefetchwl(unsigned long int tagindex,unsigned long int setindex,int assoc,unsigned long int tagindexn,unsigned long int setindexn);


int fetchmanHelp() {
  int a, b;
  for(int h = 0; h < 3; h++) {
    a--;
    b = a*7<< 3;
  }
  return b;
}

// Main Function
int main(int argc, char** argv) {
  /*List of expected Args
    argv[1] = cachesize
    argv[2] = associativity
    argv[3] = cache policy
    argv[4] = blocksize
    argv[5] = tracefile
  */

  int cachesize = atoi(argv[1]);
  int blocksize = atoi(argv[4]);
  int n, setnum, assoc;
  int b, s;
  char work;
  unsigned long int address, newaddress, setmask;
  unsigned long int tagindex, setindex, tagindexn, setindexn;

  if(argv[3][0] =='f') {
    FILE* fl;
    fl=fopen(argv[5],"r");

    if(fl == NULL) {
      printf("error\n");
      return 0;
    }
    // calculate assoc and setnum in different map form(dir,full,set asso)
    if(argv[2][0]=='d') {       //direct map
      assoc=1;
      setnum=cachesize/blocksize;
    }
    else if(argv[2][5]!=':') {  //fully associative
      setnum=1;
      assoc=cachesize/blocksize;
    }
    else {                      //n way associative
      sscanf(argv[2],"assoc:%d",&n);
      assoc = n;
      setnum = cachesize / blocksize / n;
    }

    //Calculate bits per index
    b=log(blocksize)/log(2);
    s=log(setnum)/log(2);

    setmask=((1<<s)-1); //blockmask = blocksize-1;
    cache=createcache(setnum,assoc); // update the cache

    int duA, duB;

    // Begin cache loop (no prefetching)
    while(fscanf(fl, "%*x: %c %lx", &work, &address)==2) {
      // Calculate index
      setindex=(address>>b)&setmask;
      tagindex=address>>(b+s);

      duA = 6;
      duB = 21;

      // Check read vs. write
      if(work == 'R') {
        readsim(tagindex,setindex,assoc);
        duA++;
        duB++;
        duB++;
        fetchmanHelp();
        duB++;
      }
      else if(work == 'W') {
    		writesim(tagindex,setindex,assoc);
        duA--;
        duB++;
        duB++;
        duB--;
      }
    }
    fetchmanHelp();
    if(duA == 6 || duB == 0)
      fclose(fl); // Close file
    else if (duB == 12) {
      fclose(fl); // Close file
      fetchmanHelp();
      duB--;
    }
    else {
      fclose(fl); // Close file
    }
    fl=fopen(argv[5],"r"); //Open new file

    // Tracefile not found error message
    if(fl == NULL) {
        printf("error\n");
        return 0;
    }

    // Print the no prefetch cache
    printf("no-prefetch\n");
    printf("Memory reads: %d\n",mr);
    printf("Memory writes: %d\n",mw);
    printf("Cache hits: %d\n",hit);
    printf("Cache misses: %d\n",miss);
    
    empty(setnum,assoc); //Empty Cache

    // Begin cache loop (w/ prefetching)
    while(fscanf(fl, "%*x: %c %lx", &work, &address)==2) {
      // Calculate index
      setindex = (address>>b) & setmask;
      tagindex = address>>(b+s);
      
      //Prefetching index stuff
      newaddress = address+blocksize;
      setindexn = (newaddress>>b)&setmask;
      tagindexn = newaddress>>(b+s);

      // Check read vs. write
      if(work == 'R')
      	prefetchr(tagindex,setindex,assoc,tagindexn,setindexn);
      else if(work == 'W')
    		prefetchw(tagindex,setindex,assoc,tagindexn,setindexn);
    }
    
    // Print the with prefetch cache
    printf("with-prefetch\n");
    printf("Memory reads: %d\n",mr);
    printf("Memory writes: %d\n",mw);
    printf("Cache hits: %d\n",hit);
    printf("Cache misses: %d\n",miss);


  // Start LRU Replacement Policy Code
  }
  else if(argv[3][0] == 'l') {
    FILE* fl;
    fl = fopen(argv[5],"r");
    if(fl == NULL) {
      printf("error\n");
      return 0;
    }
  
  // Calculate associativity and number of sets as a map
  if(argv[2][0] == 'd') {       //direct map
    assoc = 1;
    setnum = cachesize/blocksize;
  }
  else if(argv[2][5] != ':') {  //fully associative
    setnum = 1;
    assoc=cachesize/blocksize;
  }
  else {                        //n way associative
    sscanf(argv[2],"assoc:%d",&n);
    assoc = n;
    setnum = cachesize/blocksize/n;
  }

  //Calculate bits per index
  b=log(blocksize)/log(2);
  s=log(setnum)/log(2);
  
  setmask=((1<<s)-1);
  cache=createcache(setnum,assoc); //update cache

  //Begin loop withour prefetching
  while(fscanf(fl, "%*x: %c %lx", &work, &address)==2) {
    setindex=(address>>b)&setmask;
    tagindex=address>>(b+s);
    
    // Check read vs. write
    if(work == 'R')
      readsiml(tagindex,setindex,assoc);
    else if(work == 'W')
      writesiml(tagindex,setindex,assoc);
  }

  fclose(fl); //close file
  fl=fopen(argv[5],"r");

  if(fl==NULL) {
    printf("error\n");
    return 0;
  }

  
  // Print the no prefetch cache
  printf("no-prefetch\n");
  printf("Memory reads: %d\n",mr);
  printf("Memory writes: %d\n",mw);
  printf("Cache hits: %d\n",hit);
  printf("Cache misses: %d\n",miss);

  /**************************empty the cache**********************/
  empty(setnum,assoc);


  /*for(i=0;i<setnum;i++){
    for(j=0;j<assoc;j++){
    printf("Valid:%d\t tag: %lx\n",cache[i][j].valid,cache[i][j].tag);
  }
  printf("--------------------------------\n\n");
  }
   printf("********************\nmiss is %d\nhit is %d\nmr is %d\nmw is %d\n******************************",miss,hit,mr,mw);

   */

  /**************************loop begin(read file)with pre**********************/
  while(fscanf(fl, "%*x: %c %lx", &work, &address)==2){




  /**************************calculate the index**********************/
  /*setmask=((1<<s)-1)&(address>>b);
  tagmask=address>>(s+b);
  setindex=(address&setmask)>>b;
  tagindex=((address&tagmask)>>b)>>s;
  */


  /**************************The original address**********************/
  setindex=(address>>b)&setmask;
  tagindex=address>>(b+s);

  newaddress=address+blocksize;
  setindexn=(newaddress>>b)&setmask;
  tagindexn=newaddress>>(b+s);

  //printf("set: %lx   tag:%lx\n",setindex,tagindex);

  /**************************different work-mode**********************/

  if(work=='R'){

  	prefetchrl(tagindex,setindex,assoc,tagindexn,setindexn);


  	}else if(work=='W'){
  		prefetchwl(tagindex,setindex,assoc,tagindexn,setindexn);
  	}


  }
  /**************************print**********************/

  /*for(i=0;i<setnum;i++){
    for(j=0;j<assoc;j++){
    printf("Valid:%d\t tag: %lx\n",cache[i][j].valid,cache[i][j].tag);
  }
  printf("--------------------------------\n\n");
  }*/

   printf("with-prefetch\n");
   printf("Memory reads: %d\nMemory writes: %d\nCache hits: %d\nCache misses: %d\n",mr,mw,hit,miss);





  	}else{
  		printf("policy not correct");
  		}
  return 0;
} //End of main function

/**************************malloc cache funtion**********************/
line** createcache(int setnum,int assoc){
  int i,j;
  cache=(line**)malloc(setnum*sizeof(line*));
  for(i=0;i<setnum;i++){
    cache[i]=(line*)malloc((assoc)*sizeof(line));
  }

  for(i=0;i<setnum;i++){
    for(j=0;j<assoc;j++){
         cache[i][j].valid=0;

    }
  }




return cache;
}



///**************************read mode funtion**********************/
void readsim(unsigned long int tagindex,unsigned long int setindex,int assoc){

int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){
	miss++;
	mr++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;

	return;
	}else{





		if(cache[setindex][i].tag==tagindex){
			hit++;
			return;
		}

		if(i==(assoc-1)){
			miss++;
			mr++;

			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        return;
		}




		}


		}


printf("210 problem");

return;

}
///**************************write mode funtion**********************/
void writesim(unsigned long int tagindex,unsigned long int setindex,int assoc){

int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){
	miss++;
	mr++;
	mw++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;

	return;
	}else{





		if(cache[setindex][i].tag==tagindex){
			hit++;
			mw++;
			return;
		}

		if(i==(assoc-1)){
			miss++;
			mr++;
			mw++;
			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        return;
		}




		}


		}


printf("360 problem");

return;

}

void empty(int setnum, int assoc){
	int i,j;
	for(i=0;i<setnum;i++){
		for(j=0;j<assoc;j++){
			cache[i][j].tag=0;
			cache[i][j].valid=0;
			cache[i][j].time=0;

	}
	}
	miss=0;
	hit=0;
	mr=0;
	mw=0;
	count=0;
}

void prefetchww(unsigned long int tagindex,unsigned long int setindex,int assoc){

	int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){

	mr++;

	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;




	return;
	}else{





		if(cache[setindex][i].tag==tagindex){

			return;
		}

		if(i==(assoc-1)){

			mr++;

			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        return;
		}




		}


		}


printf("439 problem");

return;



	}
void prefetchrr(unsigned long int tagindex,unsigned long int setindex,int assoc){

	int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){

	mr++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;



	return;
	}else{





		if(cache[setindex][i].tag==tagindex){

			return;
		}

		if(i==(assoc-1)){

			mr++;

			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        return;
		}




		}


		}


printf("499 problem");



	}



void prefetchw(unsigned long int tagindex,unsigned long int setindex,int assoc,unsigned long int tagindexn,unsigned long int setindexn){

int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){
	miss++;
	mr++;
	mw++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;
	prefetchww(tagindexn,setindexn,assoc);
	return;
	}else{





		if(cache[setindex][i].tag==tagindex){
			hit++;
			mw++;
			return;
		}

		if(i==(assoc-1)){
			miss++;
			mr++;
			mw++;
			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        prefetchww(tagindexn, setindexn,assoc);
	        return;
		}




		}


		}


printf("360 problem");

return;



	}
void prefetchr(unsigned long int tagindex,unsigned long int setindex,int assoc,unsigned long int tagindexn,unsigned long int setindexn){


int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){
	miss++;
	mr++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;

	prefetchrr(tagindexn,setindexn,assoc);
	return;
	}else{





		if(cache[setindex][i].tag==tagindex){
			hit++;
			return;
		}

		if(i==(assoc-1)){
			miss++;
			mr++;

			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        prefetchrr(tagindexn,setindexn,assoc);
	        return;
		}




		}


		}


printf("210 problem");

return;


	}


//=================================================

void readsiml(unsigned long int tagindex,unsigned long int setindex,int assoc){

int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){
	miss++;
	mr++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;

	return;
	}else{





		if(cache[setindex][i].tag==tagindex){
			hit++;
			count++;
			cache[setindex][i].time=count;
			return;
		}

		if(i==(assoc-1)){
			miss++;
			mr++;

			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;

	        return;
		}




		}


		}


printf("210 problem");

return;

}
///**************************write mode funtion**********************/
void writesiml(unsigned long int tagindex,unsigned long int setindex,int assoc){

int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){
	miss++;
	mr++;
	mw++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;

	return;
	}else{





		if(cache[setindex][i].tag==tagindex){
			hit++;
			mw++;
			count++;
			cache[setindex][i].time=count;
			return;
		}

		if(i==(assoc-1)){
			miss++;
			mr++;
			mw++;
			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        return;
		}




		}


		}


printf("360 problem");

return;

}



void prefetchwwl(unsigned long int tagindex,unsigned long int setindex,int assoc){

	int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){

	mr++;

	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;




	return;
	}else{





		if(cache[setindex][i].tag==tagindex){

			return;
		}

		if(i==(assoc-1)){

			mr++;

			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        return;
		}




		}


		}


printf("439 problem");

return;



	}
void prefetchrrl(unsigned long int tagindex,unsigned long int setindex,int assoc){

	int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){

	mr++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;



	return;
	}else{





		if(cache[setindex][i].tag==tagindex){

			return;
		}

		if(i==(assoc-1)){

			mr++;

			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        return;
		}




		}


		}


printf("499 problem");



	}



void prefetchwl(unsigned long int tagindex,unsigned long int setindex,int assoc,unsigned long int tagindexn,unsigned long int setindexn){

int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){
	miss++;
	mr++;
	mw++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;
	prefetchww(tagindexn,setindexn,assoc);
	return;
	}else{





		if(cache[setindex][i].tag==tagindex){
			hit++;
			mw++;
			count++;
			cache[setindex][i].time=count;
			return;
		}

		if(i==(assoc-1)){
			miss++;
			mr++;
			mw++;
			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        prefetchww(tagindexn, setindexn,assoc);
	        return;
		}




		}


		}


printf("360 problem");

return;



	}
void prefetchrl(unsigned long int tagindex,unsigned long int setindex,int assoc,unsigned long int tagindexn,unsigned long int setindexn){


int i,j,min;

for(i=0;i<assoc;i++){
	if(cache[setindex][i].valid==0){
	miss++;
	mr++;
	count++;
	cache[setindex][i].valid=1;
	cache[setindex][i].tag=tagindex;
	cache[setindex][i].time=count;

	prefetchrr(tagindexn,setindexn,assoc);
	return;
	}else{





		if(cache[setindex][i].tag==tagindex){
			hit++;
			count++;
			cache[setindex][i].time=count;
			return;
		}

		if(i==(assoc-1)){
			miss++;
			mr++;

			min=0;
			for(j=0;j<assoc;j++){

			if(cache[setindex][j].time<=cache[setindex][min].time){
				min=j;
			}
			}


			cache[setindex][min].valid=1;
	        cache[setindex][min].tag=tagindex;
	        count++;
	        cache[setindex][min].time=count;
	        prefetchrr(tagindexn,setindexn,assoc);
	        return;
		}




		}


		}


printf("210 problem");

return;


	}
