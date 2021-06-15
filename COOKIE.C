/*
 *
 * cookie.c
 * Tuesday, 9/17/1996.
 *
 */

#include <io.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GnuType.h>
#include <GnuMisc.h>



PUINT puClock = (PUINT) 0x0000046C;

int main (int argc, char *argv[])
   {
   CHAR  sz [256];
   FILE  *fp;
   UINT  c;
   ULONG ulLen;

   srand (*puClock);

   strcpy (sz, argv[0]);
   *strchr (sz, '.') = '\0';
   strcat (sz, ".txt");
   if (!(fp = fopen (sz, "rt")))
      return printf ("It figures I can't even open the file: %s", sz);

   ulLen = filelength (fileno(fp));
   fseek (fp, RandULong(ulLen), SEEK_SET);

   while ((c = getc (fp)) != EOF)
      if (c == '\n' &&  getc (fp) == '\n')
         break;

   while (fgets (sz, 80, fp) && *sz != '\n')
      printf ("%s", sz);

   fclose (fp);
   return 0;
   }

