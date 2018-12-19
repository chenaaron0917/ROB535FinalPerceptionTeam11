   /* print files in current directory with specific file extension */
   #include <string.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <dirent.h>

   /* when return 1, scandir will put this dirent to the list */
   static int parse_ext(const struct dirent *dir)
   {
     if(!dir)
       return 0;

     if(dir->d_type == DT_REG) { /* only deal with regular file */
         const char *ext = strrchr(dir->d_name,'.');
         if((!ext) || (ext == dir->d_name))
           return 0;
         else {
           if(strcmp(ext, ".jpg") == 0)
             return 1;
         }
     }

     return 0;
   }

   static int parse_folder(const struct dirent *dir)
   {
     if(!dir)
       return 0;

     if(dir->d_type == DT_DIR) { /* only deal with directory */
        if (strcmp(dir->d_name, "..") == 0 || strcmp(dir->d_name, ".") == 0) {
            return 0;
        } else {
            return 1;
        }
     }

     return 0;
   }
    char *remove_ext (char* mystr, char dot, char sep) {
        char *retstr, *lastdot, *lastsep;

        // Error checks and allocate string.

        if (mystr == NULL)
            return NULL;
        if ((retstr = malloc (strlen (mystr) + 1)) == NULL)
            return NULL;

        // Make a copy and find the relevant characters.

        strcpy (retstr, mystr);
        lastdot = strrchr (retstr, dot);
        lastsep = (sep == 0) ? NULL : strrchr (retstr, sep);

        // If it has an extension separator.

        if (lastdot != NULL) {
            // and it's before the extenstion separator.

            if (lastsep != NULL) {
                if (lastsep < lastdot) {
                    // then remove it.

                    *lastdot = '\0';
                }
            } else {
                // Has extension separator with no path separator.

                *lastdot = '\0';
            }
        }

        // Return the modified string.

        return retstr;
    }
   int main(void)
   {
        struct dirent **namelist_folder;
        int n_folder;
        char directory[256] = "/home/vincegong/Documents/autodriving/deploy/test";
        n_folder = scandir(directory, &namelist_folder, parse_folder, alphasort);

        if (n_folder < 0) {
            perror("scandir");
            return 1;
        } else {
            int i = 0;
            while (i<n_folder) {

                struct dirent **namelist;
                int n;
                int j = 0;
                int length;
                char filename[256];
                length = sprintf(filename,"%s/%s",directory,namelist_folder[i]->d_name);
                n = scandir(filename, &namelist, parse_ext, alphasort);
                if (n < 0) {
                    perror("scandir");
                    return 1;
                } else {
                        int j = 0;
                        while (j<n) {
                        char *s;
                        printf("%s/%s\n", namelist_folder[i]->d_name,(s = remove_ext (namelist[j]->d_name, '_', '/')));free (s);
                        printf("%s/%s/%s\n", directory,namelist_folder[i]->d_name,namelist[j]->d_name);
                        free(namelist[j]);
                        ++j;
                    }
                    free(namelist);
                }
                free(namelist_folder[i]);
                ++i;
            }
            free(namelist_folder);
        }

        return 0;
   }