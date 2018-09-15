#ifndef readfile_h
#define readfile_h

int readfile(char *file, person **pArray, phone **nArray);
int parceplacePerson(char *buf, person **pArray, int pindex);
int parceplacePhone(char *buf, person **pArray, phone **nArray, int pindex, int nindex);

#endif
