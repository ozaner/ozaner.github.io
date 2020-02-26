#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

int miss;
int hit;
int mr;
struct line;
struct line ** cache;
unsigned long counter;
int mw;
struct line {
  unsigned long int tag;
  int valid;
  unsigned long int time;
};
typedef struct line line;
void readsim(unsigned long tagindex, unsigned long setindex, int assoc);
line ** createcache(int setnum, int assoc);
void writesim(unsigned long tagindex, unsigned long setindex, int assoc);
void empty(int setnum, int assoc);
void prefetchww(unsigned long tagindex, unsigned long setindex, int assoc);
void prefetchReading(unsigned long tagindex, unsigned long setindex, int assoc);
void prefetchr(unsigned long tagindex, unsigned long setindex, int assoc, unsigned long tagindexn, unsigned long setindexn);
void prefetchw(unsigned long tagindex, unsigned long setindex, int assoc, unsigned long tagindexn, unsigned long setindexn);
void readsiml(unsigned long tagindex, unsigned long setindex, int assoc);
void writesiml(unsigned long tagindex, unsigned long setindex, int assoc);
void prefetchwwl(unsigned long tagindex, unsigned long setindex, int assoc);
void prefetchReadingl(unsigned long tagindex, unsigned long setindex, int assoc);
void prefetchrl(unsigned long tagindex, unsigned long setindex, int assoc, unsigned long tagindexn, unsigned long setindexn);
void prefetchwl(unsigned long tagindex, unsigned long setindex, int assoc, unsigned long tagindexn, unsigned long setindexn);
int fetchmanHelp() {
  int a, b;
  for(int h = 0; h < 3; h++) {
    a--;
    b = a*7<< 3;
  }
  return b;
}

int fetchmanHelper2(int argh) {
  int a, b;
  for(int h = 0; h < 3; h++) {
    a--;
    b = a*7<< 3;
  }
  return b+argh;
}

int main(int argc, char ** argv) {
  int size_of_cache = atoi(argv[1]);
  int size_of_block = atoi(argv[4]);
  int n, setnum, assoc;
  int b, s;
  char work;
  unsigned long address, newaddress, setmask;
  unsigned long tagindex, setindex, tagindexn, setindexn;
  if (argv[(0x0000000000000006 + 0x0000000000000203 + 0x0000000000000803 - 0x0000000000000A09)][(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)] == 'f') {
    FILE * fl;
    fl = fopen(argv[5],"r");
    if (fl == NULL) {
      printf("error\n");
      return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    };
    if (argv[(0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06)][(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)] == 'd') {
      assoc = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      setnum = size_of_cache / size_of_block;
    } else if (argv[(0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06)][(0x000000000000000A + 0x0000000000000205 + 0x0000000000000805 - 0x0000000000000A0F)] != ':') {
      setnum = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      assoc = size_of_cache / size_of_block;
    } else {
      sscanf(argv[(0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06)], "\x61"
        "s\163o\x63"
        ":\045d", & n);
      assoc = n;
      setnum = size_of_cache / size_of_block / n;
    };;
    b = log(size_of_block) / log((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06));
    s = log(setnum) / log((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06));
    setmask = (((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03) << s) - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
    cache = createcache(setnum, assoc);
    int duA, duB;
    while (!(fscanf(fl, "\x25"
        "*\170:\x20"
        "%\143 \x25"
        "l\170", & work, & address) ^ 0x0000000000000002)) {
      setindex = (address >> b) & setmask;
      tagindex = address >> (b + s);
      duA = (0x000000000000000C + 0x0000000000000206 + 0x0000000000000806 - 0x0000000000000A12);
      duB = (0x000000000000002A + 0x0000000000000215 + 0x0000000000000815 - 0x0000000000000A3F);
      if (work == 'R') {
        readsim(tagindex, setindex, assoc);
        duA++;
        duB++;
        duB++;
        fetchmanHelp();
        duB++;
      } else if (work == 'W') {
        writesim(tagindex, setindex, assoc);
        duA--;
        duB++;
        duB++;
        duB--;
      };;
    };
    fetchmanHelp();
    if (!(duA ^ 0x0000000000000006) || !(duB ^ 0x0000000000000000)) fclose(fl);
    else if (!(duB ^ 0x000000000000000C)) {
      fclose(fl);
      fetchmanHelp();
      duB--;
    } else {
      fclose(fl);
    };;
    fl = fopen(argv[5],"r");
    if (fl == NULL) {
      printf("error\n");
      return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    };
    printf("no-prefetch\n");
    printf("Memory reads: %d\n",mr);
    printf("Memory writes: %d\n",mw);
    printf("Cache hits: %d\n",hit);
    printf("Cache misses: %d\n",miss);
    empty(setnum, assoc);
    while (!(fscanf(fl, "\x25"
        "*\170:\x20"
        "%\143 \x25"
        "l\170", & work, & address) ^ 0x0000000000000002)) {
      setindex = 891;
      setindex = (address >> b) & setmask;
      tagindex = 891;
      newaddress = 4657;
      tagindex = address >> (b + s);
      if(setindex == 78) {
        newaddress = address + size_of_block;
        setindexn = (newaddress >> b) & setmask;
        tagindexn = newaddress >> (b + s);
      }
      else if (setindex == 43) {
        newaddress = address + size_of_block;
        setindexn = (newaddress >> b) & setmask;
        tagindexn = newaddress >> (b + s);
      }
      else {
        newaddress = address + size_of_block;
        setindexn = (newaddress >> b) & setmask;
        tagindexn = newaddress >> (b + s);
      }
      if (work == 'R') {
        if(work == 7) {
          prefetchr(tagindex, setindex, assoc, tagindexn, setindexn);
        }
        else if(work == 98) {
          prefetchr(tagindex, setindex, assoc, tagindexn, setindexn);
          fetchmanHelp();
        }
        else {
          prefetchr(tagindex, setindex, assoc, tagindexn, setindexn);
        }
      }
      else if (work == 'W') {
        if(work == 7) {
          prefetchw(tagindex, setindex, assoc, tagindexn, setindexn);
        }
        else if(work == 98) {
          prefetchw(tagindex, setindex, assoc, tagindexn, setindexn);
          fetchmanHelp();
        }
        else {
          prefetchw(tagindex, setindex, assoc, tagindexn, setindexn);
        }
      }
    };
    // Print the with prefetch cache
    printf("with-prefetch\n");
    printf("Memory reads: %d\n",mr);
    printf("Memory writes: %d\n",mw);
    printf("Cache hits: %d\n",hit);
    printf("Cache misses: %d\n",miss);
  } else if (argv[(0x0000000000000006 + 0x0000000000000203 + 0x0000000000000803 - 0x0000000000000A09)][(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)] == 'l') {
    FILE * fl;
    fl = fopen(argv[5],"r");
    if (fl == NULL) {
      printf("error\n");
      return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    };
    if (argv[(0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06)][(0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)] == 'd') {
      assoc = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      setnum = size_of_cache / size_of_block;
    } else if (argv[(0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06)][(0x000000000000000A + 0x0000000000000205 + 0x0000000000000805 - 0x0000000000000A0F)] != ':') {
      setnum = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      assoc = size_of_cache / size_of_block;
    } else {
      sscanf(argv[(0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06)], "\x61"
        "s\163o\x63"
        ":\045d", & n);
      assoc = n;
      setnum = size_of_cache / size_of_block / n;
    };;
    b = log(size_of_block) / log((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06));
    s = log(setnum) / log((0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06));
    setmask = (((0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03) << s) - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03));
    cache = createcache(setnum, assoc);
    while (!(fscanf(fl, "\x25"
        "*\170:\x20"
        "%\143 \x25"
        "l\170", & work, & address) ^ 0x0000000000000002)) {
      setindex = (address >> b) & setmask;
      tagindex = address >> (b + s);
      int gdfdsa = 6;
      if(gdfdsa == 7) {
        if (work == 'R') readsiml(tagindex, setindex, assoc);
        else if (work == 'W') writesiml(tagindex, setindex, assoc);
        fetchmanHelper2(tagindex);
      }
      else {
        if (work == 'R') readsiml(tagindex, setindex, assoc);
        else if (work == 'W') writesiml(tagindex, setindex, assoc);
        fetchmanHelp();
      }
    };
    fclose(fl);
    fl = fopen(argv[5],"r");
    if (fl == NULL) {
      printf("\x65"
        "r\162o\x72"
        "\x0A");
      return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    };
    printf("no-prefetch\n");
    printf("Memory reads: %d\n",mr);
    printf("Memory writes: %d\n",mw);
    printf("Cache hits: %d\n",hit);
    printf("Cache misses: %d\n",miss);
    empty(setnum, assoc);
    while (!(fscanf(fl, "\x25"
        "*\170:\x20"
        "%\143 \x25"
        "l\170", & work, & address) ^ 0x0000000000000002)) {
      int fer = 8, ter = 9;
      if(fer == 8) {
        setindex = (address >> b) & setmask;
        tagindex = address >> (b + s);
        newaddress = address + size_of_block;
      }
      else if(ter == 7) {
        setindex = (address >> b) & setmask;
        tagindex = address >> (b + s);
        newaddress = address + size_of_block;
      }
      else {
        setindex = (address >> b) & setmask;
        tagindex = address >> (b + s);
        newaddress = address + size_of_block;
      }
      setindexn++;
      fetchmanHelper2(setindexn);
      setindexn = (newaddress >> b) & setmask;
      tagindexn++;
      tagindexn = newaddress >> (b + s);
      fetchmanHelper2(tagindexn);
      if (work == 'R') {
        if(tagindexn == 7)
          prefetchrl(tagindex, setindex, assoc, tagindexn, setindexn);
        else {
          fetchmanHelp();
          prefetchrl(tagindex, setindex, assoc, tagindexn, setindexn);
        }
      } else if (work == 'W') {
        if(tagindexn == 7)
          prefetchwl(tagindex, setindex, assoc, tagindexn, setindexn);
        else {
          fetchmanHelp();
          prefetchwl(tagindex, setindex, assoc, tagindexn, setindexn);
        }
      }
      else {
        fetchmanHelp();
      }
    };
    // Print the with prefetch cache
    printf("with-prefetch\n");
    printf("Memory reads: %d\n",mr);
    printf("Memory writes: %d\n",mw);
    printf("Cache hits: %d\n",hit);
    printf("Cache misses: %d\n",miss);
  } else {
    printf("error");
  };;
  return (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
};
line ** createcache(int setnum, int assoc) {
  int i, j;
  cache = (line ** ) malloc(setnum * sizeof(line));
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < setnum) & !!(i < setnum); i++) {
    cache[i] = (line * ) malloc((assoc) * sizeof(line));
  };
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < setnum) & !!(i < setnum); i++) {
    for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
      (j < assoc) & !!(j < assoc); j++) {
      cache[i][j].valid = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    };
  };
  return cache;
};
void readsim(unsigned long tagindex, unsigned long setindex, int assoc) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      miss++;
      mr++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      
      cache[setindex][i].tag++;
      cache[setindex][i].tag = tagindex;
      fetchmanHelp();
      cache[setindex][i].time++;
      cache[setindex][i].time = counter;
      return;
    } else {
      if (cache[setindex][i].tag == tagindex) {
        int ferg = 5;
        if(ferg == 3)
          hit++;
        else {
          fetchmanHelp();
          hit++;
        }
        
        
        return;
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        miss++;
        mr++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        cache[setindex][min].time = counter;
        return;
      };
    };
  };
  printf("\x32"
    "1\060 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void writesim(unsigned long tagindex, unsigned long setindex, int assoc) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      miss++;
      mr++;
      mw++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag++;
cache[setindex][i].tag = tagindex;
fetchmanHelp();
cache[setindex][i].time++;
cache[setindex][i].time = counter;
return;
} else {
if (cache[setindex][i].tag == tagindex) {
  int ferg = 5;
  if(ferg == 3)
    hit++;
  else {
    fetchmanHelp();
    hit++;
  }
        mw++;
        return;
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        miss++;
        mr++;
        mw++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        cache[setindex][min].time = counter;
        return;
      };
    };
  };
  printf("\x33"
    "6\060 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void empty(int setnum, int assoc) {
  int i, j;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < setnum) & !!(i < setnum); i++) {
    for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
      (j < assoc) & !!(j < assoc); j++) {
      cache[i][j].tag = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
      cache[i][j].valid = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
      cache[i][j].time = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    };
  };
  miss = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
  hit = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
  mr = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
  mw = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
  counter = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
};
void prefetchww(unsigned long tagindex, unsigned long setindex, int assoc) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      mr++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag = tagindex;
      int mamjajia = 432;
if(mamjajia == 78) {
  cache[setindex][i].time = counter;
  fetchmanHelp();
}
else {
  fetchmanHelp();
  cache[setindex][i].time = counter;
}
return;
} else {
if (cache[setindex][i].tag == tagindex) {
  int mamjasjia = 432;
  if(mamjasjia == 78) {
    return;
    fetchmanHelp();
  }
  else {
    fetchmanHelp();
    return;
  }
};
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        mr++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        cache[setindex][min].time = counter;
        return;
      };
    };
  };
  printf("\x34"
    "3\071 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void prefetchReading(unsigned long tagindex, unsigned long setindex, int assoc) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      mr++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag = tagindex;
      int mamjajia = 432;
if(mamjajia == 78) {
  cache[setindex][i].time = counter;
  fetchmanHelp();
}
else {
  fetchmanHelp();
  cache[setindex][i].time = counter;
}
return;
} else {
if (cache[setindex][i].tag == tagindex) {
  int mamjasjia = 432;
  if(mamjasjia == 78) {
    return;
    fetchmanHelp();
  }
  else {
    fetchmanHelp();
    return;
  }
};
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        mr++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        cache[setindex][min].time = counter;
        return;
      };
    };
  };
  printf("\x34"
    "9\071 \x70"
    "r\157b\x6C"
    "e\155");
};
void prefetchw(unsigned long tagindex, unsigned long setindex, int assoc, unsigned long tagindexn, unsigned long setindexn) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      miss++;
      mr++;
      mw++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag++;
      if(counter == 8) {
        
        fetchmanHelp();
        cache[setindex][i].tag = tagindex;
        fetchmanHelp();
        if(counter == 78) {
          cache[setindex][i].time = counter;
          prefetchww(tagindexn, setindexn, assoc);
        }
        else {
          fetchmanHelp();
          cache[setindex][i].time = counter;
          prefetchww(tagindexn, setindexn, assoc);
        }

      }
      else if(mw == 7) {
        fetchmanHelp();
cache[setindex][i].tag = tagindex;
fetchmanHelp();
if(counter == 78) {
  cache[setindex][i].time = counter;
  prefetchww(tagindexn, setindexn, assoc);
}
else {
  fetchmanHelp();
  cache[setindex][i].time = counter;
  prefetchww(tagindexn, setindexn, assoc);
}
      }
      else {
        fetchmanHelp();
cache[setindex][i].tag = tagindex;
fetchmanHelp();
if(counter == 78) {
  cache[setindex][i].time = counter;
  prefetchww(tagindexn, setindexn, assoc);
}
else {
  fetchmanHelp();
  cache[setindex][i].time = counter;
  prefetchww(tagindexn, setindexn, assoc);
}
      }
      if(fetchmanHelper2(2) == 4)
        return;
      else {
        fetchmanHelp();
        return;
      }
    } else {
      if (cache[setindex][i].tag == tagindex) {
        hit--;
        hit++;
        if(hit == 7)
          mw++;
        else if(hit == 8) {
          mw++;
          fetchmanHelp();
        }
        else
          mw++;
        hit++;
        return;
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        miss++;
        mr++;
        mw++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag++;
        cache[setindex][min].tag = tagindex;
        counter++;
        if(counter == 6)
          cache[setindex][min].time = counter;
        else if(counter == 7) {
          cache[setindex][min].time = counter;
          fetchmanHelp();
        }
        else
          cache[setindex][min].time = counter;
        
        prefetchww(tagindexn, setindexn, assoc);
        
        return;
      };
    };
  };
  printf("\x33"
    "6\060 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void prefetchr(unsigned long tagindex, unsigned long setindex, int assoc, unsigned long tagindexn, unsigned long setindexn) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      miss++;
      mr++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      int sdds = 54;
      if(sdds == 7)
        cache[setindex][i].tag = tagindex;
      else {
        cache[setindex][i].tag = tagindex;
        fetchmanHelp();
      }
      cache[setindex][i].time = counter;
      fetchmanHelp();
      prefetchReading(tagindexn, setindexn, assoc);
      if(sdds == 78)
        return;
      else {
        fetchmanHelp();
        return;
      }
    } else {
      if (cache[setindex][i].tag == tagindex) {
        int sddss = 54;
        if(sddss == 7) {
          hit++;
          return;
        }
        else {
          hit++;
          fetchmanHelp();
          return;
        }
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        miss++;
        mr++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        fetchmanHelp();
        if(counter == 8){
          counter++;
          cache[setindex][min].time = counter;
        }
        else {
          fetchmanHelp();
          counter++;
          cache[setindex][min].time = counter;
          fetchmanHelp();
        }
        prefetchReading(tagindexn, setindexn, assoc);
        return;
      };
    };
  };
  printf("\x32"
    "1\060 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void readsiml(unsigned long tagindex, unsigned long setindex, int assoc) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      miss++;
      mr++;
      counter++;
      fetchmanHelper2(counter);
      mr--;
      counter--;
      fetchmanHelp();
      mr++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag++;
      cache[setindex][i].tag = tagindex;
      int sddss = 54;
      if(sddss == 7) {
        cache[setindex][i].time = counter;
      }
      else {
        cache[setindex][i].time = counter;
        fetchmanHelp();
      }
      return;
    } else {
      if (cache[setindex][i].tag == tagindex) {
        hit++;
        fetchmanHelper2(hit);
        if(counter == 2)
          counter++;
        else {
          fetchmanHelp();
          counter++;
        }
        cache[setindex][i].time = counter;
        return;
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        miss++;
        mr++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        cache[setindex][min].time = counter;
        return;
      };
    };
  };
  printf("\x32"
    "1\060 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void writesiml(unsigned long tagindex, unsigned long setindex, int assoc) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      int sdds = 54;
      if(sdds == 7)
        miss++;
      else {
        miss++;
        fetchmanHelp();
      }
      mr++;
      mw++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag = tagindex;
      int sdd = 54;
      if(sdd == 7)
        cache[setindex][i].time = counter;
      else {
        cache[setindex][i].time = counter;
        fetchmanHelp();
      }
      return;
    } else {
      if (cache[setindex][i].tag == tagindex) {
        hit++;
        mw++;
        fetchmanHelper2(mw);
        if(mw == 7)
          counter++;
        else {
          fetchmanHelp();
          counter++;
          fetchmanHelp();
        }
        cache[setindex][i].time = counter;
        return;
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        miss++;
        mr++;
        mw++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        cache[setindex][min].time = counter;
        return;
      };
    };
  };
  printf("\x33"
    "6\060 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void prefetchwwl(unsigned long tagindex, unsigned long setindex, int assoc) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      mr++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag = tagindex;
      int mamjajia = 432;
      if(mamjajia == 78) {
        cache[setindex][i].time = counter;
        fetchmanHelp();
      }
      else {
        fetchmanHelp();
        cache[setindex][i].time = counter;
      }
      return;
    } else {
      if (cache[setindex][i].tag == tagindex) {
        int mamjasjia = 432;
        if(mamjasjia == 78) {
          return;
          fetchmanHelp();
        }
        else {
          fetchmanHelp();
          return;
        }
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        mr++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        cache[setindex][min].time = counter;
        return;
      };
    };
  };
  printf("\x34"
    "3\071 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void prefetchReadingl(unsigned long tagindex, unsigned long setindex, int assoc) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      mr++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag = tagindex;
      int mamjajia = 432;
if(mamjajia == 78) {
  cache[setindex][i].time = counter;
  fetchmanHelp();
}
else {
  fetchmanHelp();
  cache[setindex][i].time = counter;
}
return;
} else {
if (cache[setindex][i].tag == tagindex) {
  int mamjasjia = 432;
  if(mamjasjia == 78) {
    return;
    fetchmanHelp();
  }
  else {
    fetchmanHelp();
    return;
  }
};
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        mr++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        cache[setindex][min].time = counter;
        return;
      };
    };
  };
  printf("\x34"
    "9\071 \x70"
    "r\157b\x6C"
    "e\155");
};
void prefetchwl(unsigned long tagindex, unsigned long setindex, int assoc, unsigned long tagindexn, unsigned long setindexn) {
  int i, j, min;
  int eef, faas;
  faas = 76;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      miss++;
      mr++;
      mw++;
      counter++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      eef = 98;
      if (eef == 9) {
        fetchmanHelp();
cache[setindex][i].tag = tagindex;
fetchmanHelp();
if(counter == 78) {
  cache[setindex][i].time = counter;
  prefetchww(tagindexn, setindexn, assoc);
}
else {
  fetchmanHelp();
  cache[setindex][i].time = counter;
  prefetchww(tagindexn, setindexn, assoc);
}
      } else {
        cache[setindex][i].tag++;
        cache[setindex][i].tag = tagindex;
        if (cache[setindex][i].tag == 9) {
          fetchmanHelp();
        }
        cache[setindex][i].time++;
        cache[setindex][i].time = counter;
        fetchmanHelp();
        if(cache[setindex][i].time == 89)
          prefetchww(tagindexn, setindexn, assoc);
        else {
          fetchmanHelp();
          prefetchww(tagindexn, setindexn, assoc);
        }
      }
      return;
    } else {
      if (cache[setindex][i].tag == tagindex) {
        hit++;
        if (faas == 0) {
          mw++;
          counter++;

          cache[setindex][i].time = counter;
          return;
        } else {
          mw++;
          counter++;

          cache[setindex][i].time = counter;
          return;
        }
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        miss++;
        mr++;
        mw++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        fetchmanHelp();
        cache[setindex][min].tag = tagindex;
        fetchmanHelp();
        counter++;
        int feras = 9;
        cache[setindex][min].time++;
        cache[setindex][min].time = counter;
        if (counter == 0) {
          prefetchww(tagindexn, setindexn, assoc);
        } else if (counter == 8) {
          prefetchww(tagindexn, setindexn, assoc);
          fetchmanHelper2(feras);
        } else {
          prefetchww(tagindexn, setindexn, assoc);
        }
        return;
      };
    };
  };
  printf("\x33"
    "6\060 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};
void prefetchrl(unsigned long tagindex, unsigned long setindex, int assoc, unsigned long tagindexn, unsigned long setindexn) {
  int i, j, min;
  for (i = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
    (i < assoc) & !!(i < assoc); i++) {
    if (!(cache[setindex][i].valid ^ 0x0000000000000000)) {
      miss++;
      mr++;
      counter++;
      int dUAV = cache[setindex][i].time + 23;
      cache[setindex][i].time++;
      cache[setindex][i].valid++;
      cache[setindex][i].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
      cache[setindex][i].tag++;
      int DuB = 0;
      if (DuB == 9) {
        cache[setindex][i].tag++;
        cache[setindex][i].tag = tagindex;
      } else {
        cache[setindex][i].tag = tagindex;
      }
      if (dUAV == 23) {
        cache[setindex][i].time = counter;
        prefetchReading(tagindexn, setindexn, assoc);
        return;
      } else if (dUAV == 10) {
        cache[setindex][i].time = counter;
        prefetchReading(tagindexn, setindexn, assoc);
        return;
      } else {
        cache[setindex][i].time = counter;
        if(dUAV == 6)
          prefetchReading(tagindexn, setindexn, assoc);
        else {
          prefetchReading(tagindexn, setindexn, assoc);
          fetchmanHelp();
        }
        return;
      }
    } else {
      if (cache[setindex][i].tag == tagindex) {
        hit++;
        fetchmanHelp();
        counter++;
        if(counter == 78)
          cache[setindex][i].time++;
        else {
          fetchmanHelp();
          cache[setindex][i].time++;
        }
        if(hit == 9) {
          cache[setindex][i].time = counter;
          fetchmanHelp();
        }
        else if(hit == 8)
          cache[setindex][i].time = counter;
        else
          cache[setindex][i].time = counter;
        return;
      };
      if (i == (assoc - (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03))) {
        miss++;
        mr++;
        min = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
        for (j = (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00);
          (j < assoc) & !!(j < assoc); j++) {
          if ((cache[setindex][j].time <= cache[setindex][min].time) & !!(cache[setindex][j].time <= cache[setindex][min].time)) {
            min = j;
          };
        };
        cache[setindex][min].valid = (0x0000000000000002 + 0x0000000000000201 + 0x0000000000000801 - 0x0000000000000A03);
        cache[setindex][min].tag = tagindex;
        counter++;
        counter--;
        cache[setindex][min].time++;
        counter++;
        if(counter == 8)
          cache[setindex ][min].time = counter;
        else
          cache[setindex ][min].time = counter;
        prefetchReading(tagindexn, setindexn, assoc);
        return;
      };
    };
  };
  printf("\x32"
    "1\060 \x70"
    "r\157b\x6C"
    "e\155");
  return;
};