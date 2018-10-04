#ifndef readfile_h
#define readfile_h

int openfile(int argc,char *argv[], FILE **fp);
int readfile(FILE *fp, person **pArray, int *perc, phone **nArray, int *phoc);
int parceplacePerson(char *buf, person **pArray, int pindex);
int parceplacePhone(char *buf, person **pArray, phone **nArray, int pindex, int nindex);

#endif
