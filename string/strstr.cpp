#include <iostream>
#include <string.h>

using namespace std;

/**
 * MS VC++ 6.0 RTL source 
 */
char * strstr3 (
        const char * str1,
        const char * str2
        )
{
        char *cp = (char *) str1;
        char *s1, *s2;

        if ( !*str2 )
            return((char *)str1);

        while (*cp)
        {
                s1 = cp;
                s2 = (char *) str2;

                while ( *s1 && *s2 && !(*s1-*s2) )
                        s1++, s2++;

                if (!*s2)
                        return(cp);

                cp++;
        }

        return(NULL);

}

char *strstr2(const char *str1, const char *str2) {
  char *p1, *p2, *cp;
  cp = p1 = (char *)str1;
  p2 = (char *)str2;

  if (!*str2) return p1;

  while(*cp) {
    p1 = cp;
    p2 = (char *)str2;
    while(*p1 && *p2 && (*p1==*p2)) {
      p1++;
      p2++;
    }
    if (!*p2) return cp;
    cp++;
  }
  return NULL;
}

char *strstr1(char *str1, const char *str2) {
  int l1 = strlen(str1);
  int l2 = strlen(str2);
  int i, j;
  i = j = 0;
  while(i<l1 && j<l2) {
    // cout<<str1[i]<<" vs "<<str2[j]<<endl;
    if (str1[i] == str2[j]) {
      i++;
      j++;
    }
    else {
      i = i-j+1;
      j = 0;
    }
  }
  if (j>0) {
    // cout<<"index--"<<i-j<<endl;
    return str1+i-j;
  }
  else {
    cout<<"could not find it"<<endl;
    return NULL;
  }
}

char *strstr(char *hay, char *needle) {
    // assert(hay && needle);
    char *p1, *p2, *p3;
    while(*p1) {
        p3 = p1;
        p2 = needle;
        while(*p2 && *p3 && *p2==*p3) {p2++; p3++;}
        if (!*p2) return p1;
        p1++;
    }
    return NULL;
}

int main() {
  char s1[50];
  char s2[50];
  cin>>s1;
  cin>>s2;
  cout<<strstr(s1, s2)<<endl;
  cout<<strstr1(s1, s2)<<endl;
  cout<<strstr2(s1, s2)<<endl;
  cout<<strstr3(s1, s2)<<endl;
  return 1;
}
