#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

int main(){

    std::cout << "Test" << std::endl;

    std::string path = "/Users/sammy/Documents/gcc-test/test_files/";

    DIR* dirFile = opendir( path.c_str() );
    if ( dirFile ) 
    {
        std::cout << "Dir exists" << std::endl;
        struct dirent* hFile;
        errno = 0;
        while (( hFile = readdir( dirFile )) != NULL )
        {
            if ( !strcmp( hFile->d_name, "."  )) continue;
            if ( !strcmp( hFile->d_name, ".." )) continue;
            // in linux hidden files all start with '.'
            if ( hFile->d_name[0] == '.' ) continue;

            // dirFile.name is the name of the file. Do whatever string comparison 
            // you want here. Something like:
            if ( strstr( hFile->d_name, ".pdf" )){
                std::string fromfile = path + hFile->d_name;
                std::string toFile = fromfile + "this is a test.txt";
                std::cout << fromfile << std::endl;
                int result = rename(fromfile.c_str(), toFile.c_str());
                if ( result == 0 )
                    puts ( "File successfully renamed" );
                else
                    perror( "Error renaming file" );
                //std::cout << hFile->d_name << std::endl;
            }
        }
        closedir( dirFile );
    }else{
        std::cout << "No dir" << std::endl;
    }
}

