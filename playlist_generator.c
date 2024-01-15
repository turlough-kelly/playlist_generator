#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/*This structure is for keeping records of all songs entered.*/
struct collection {
  char length[50];
  char title[50];
  char artist[50];
  char temp[50];
};
/*This structure is for keeping records of every unique artist that is entered into the program*/
struct artists
{
    char artist[50];
};
/*This function is for extracting the title of the song from a string in the format TITLE***DURATION*/
char* titleofsong(char *s, char *songtitle) {
    char *song = strrchr(s, '*');
    int size;
    int i = 0;
    if (song) {
        *song = '\0';
        songtitle = s;
        while(i < 2)
        {
        size = strlen(songtitle);
        songtitle[size-1] = '\0';
        i++;
        }
        
        return songtitle;
    }
}
/*This function is for extracting the duration of the song from a string in the format TITLE***DURATION*/
char* durationofsong(char *s) {
    char *p_sl = strrchr(s, '*');
    if (p_sl) {
    }

    return p_sl + 1;
}

int main()
{
    /*srand to seed the RNG for the program*/
    srand(time(NULL));
    /*Pointer to the file that will be accessed in the program*/
    FILE *songlist;
    /*Variables to be declared in the program*/
    const char check1[4] = "***";
    char currentline[50];
    char songtitle[50];
    char duration[50];
    char artist[50];
    char filename[30];

    /*Pointers to the 2 structs declared above*/
    struct collection *playlist;
    struct artists *artistes;

    int artistamount = 0;
    int input;
    int amount;
    int songs = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int ran;
    int minutes = 0;
    int seconds = 0;
    int songtracker[100];
    int check2;
    int check3;
    int size;
    int printedsongs;
    int count;
    int error;
    int tempmin;
    int tempsec;
    int temp;

    /*User is prompted to enter a file name to be read in.*/
    printf("Please enter a file to be read. Please ensure it is located in the same folder as this file.\nIf the file does not exist, the program will search for 'artistes+songs.txt' instead.\n--> ");
    gets(filename);
    strcat(filename,".txt");
    /*The program will attempt to open a file with the name entered.*/
    songlist = fopen(filename, "r");

    /*If the file cannot be located, this check will inform the user and the program will begin looking for artistes+songs.txt*/
    if ((songlist = fopen (filename, "r")) == NULL)
    {
        printf("File could not be opened/located. Beginning search for 'artistes+songs.txt'.\n");
        fclose(songlist);
        songlist = fopen("artistes+songs.txt", "r");
        if ((songlist = fopen ("artistes+songs.txt", "r")) == NULL)
    {
        /*If it could not be found, it will signal the program to move to the manual input*/
        printf("No file was found. Beginning manual input. Please follow the directions of the program.");
    }
    /*If a file was found in either case, it will inform the user*/
    else if ((songlist = fopen ("artistes+songs.txt", "r")) != NULL)
    {
        printf("File sucessfully opened.\n");
        strcpy(filename, "artistes+songs.txt");
    }
    }
    
    else if ((songlist = fopen (filename, "r")) != NULL)
    {
        printf("File sucessfully opened.\n");
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*If a file could not be located, the user can manually input their songs and artists.*/
    if (((songlist = fopen ("artistes+songs.txt", "r")) == NULL) && ((songlist = fopen (filename, "r")) == NULL))
    {
        /*The user will be prompted to enter how many unique artists they wish to input for.*/
        fclose(songlist);
        printf("\nHow many unique artists would you like to enter songs for?\n--> ");
        while (scanf("%d", &artistamount) != 1)
            {
                printf("\nThis input is invalid. Please try again. ");
                getchar();
            }
        printf("How many songs do you wish to enter in total?\nPlease note that only the number of songs entered here will be used throughout the program.\n--> ");
        while (scanf("%d", &songs) != 1)
            {
                printf("\nThis input is invalid. Please try again. ");
                getchar();
            }
        getchar();
        /*Memory is allocated for both structs to ensure smooth sailing and no errors/breakdowns (that would be very bad)*/
        playlist = (struct collection *)malloc(songs * sizeof(struct collection));
        artistes = (struct artists *)malloc(artistamount * sizeof(struct artists));
            /*This loop allows the user to enter the details of the songs they wish to enter.*/
            for (int i = 0; i < artistamount; i++) 
            {
                /*User inputs the name of the current artist they are entering in the songs for, which will be assigned to the songs they enter later on.*/
                 printf("What is the name of artist %d?\n--> ", i + 1);
                gets(artist);
                /*User is asked to enter how many songs this artist has in order to keep track for the program.*/
                printf("How many songs do you want to enter for this artist?\n--> ");
                while (scanf("%d", &amount) != 1)
                     {
                        printf("\nThis input is invalid. Please try again: ");
                             getchar();
                    }
                getchar();

                /*The user can now input songs for the current artist, including title and duration.*/
                for (int k = 0; k < amount; k++) 
                { 
                 printf("Please enter the song title for song %d:\n--> ", k + 1);
                 gets(playlist[l].title);
                printf("\nPlease enter its duration in the format 'MINUTES:SECONDS'. Please include the ':'.\n--> ");
                gets(playlist[l].length);
                strcat(playlist[l].length, ").");
                /*The currently entered artist is then assigned to this song*/
                strcpy(playlist[l].artist, artist);
                l++;
                }
             }
        /*When all songs have been entered, they will be printed out here*/
        printf("Here are the currently entered songs:\n");
        for(i = 0; i < (songs); i++)
        {
         printf("%s: %s (%s\n", playlist[i].artist, playlist[i].title, playlist[i].length);
        }       
    
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*If a file is located or artistes+songs.txt is opened, it will begin reading the file.*/
    else
    {
        while(fgets(currentline, sizeof(currentline), songlist) )
        {

        /*Scans through the file intitally to check how many artists and songs are present.*/
            if ( (strstr(currentline, check1) == NULL) )
                {
                    artistamount = artistamount + 1;
                }
            else
                {
                     songs = songs + 1;
                }
        }   
        /*Prints out how many artists and songs were found and allocates memory based on this information.*/
        printf("Unique Artists: %d\nSongs: %d", artistamount, songs);
        playlist = (struct collection *)malloc(songs * sizeof(struct collection));
        artistes = (struct artists *)malloc(artistamount * sizeof(struct artists));

        fclose(songlist);

        songlist = fopen(filename, "r");

        /*Scans through the file again to copy the data on each artist and song into the allocated structs.*/
        while(fgets(currentline, sizeof(currentline), songlist) )
            {
                /*If a line does not have '***' included, the program assumes it is an artist and copies it for future use*/
                if ( (strstr(currentline, check1) == NULL))
                {
                    memset(artist, 0, sizeof(artist));
                    strcpy(artist, currentline);
                    strcpy(artistes[j].artist, currentline);
                    j++;
                }

                /*If a line contains '***', the program assumes it is a song copies the relevent information.*/
                if ( (strstr(currentline, check1) != NULL))
                {  
                    strcpy(playlist[i].length, durationofsong(currentline));
                    strcpy(playlist[i].title, titleofsong(currentline, songtitle));
                    strcat(playlist[i].length, ")");
                    strcpy(playlist[i].artist, artist);
                    i++;
                }
            }   
        fclose(songlist);
        /*The program prints out what songs were found, and by whom, in the order they were found.*/
        printf("\n\n\nHere are the songs that were found:\n");
        for(i = 0; i < (songs); i++)
            {
                printf("%s: %s (%s\n", playlist[i].artist, playlist[i].title, playlist[i].length);
            }
    }
    /*With all the information collected, the program will now begin to produce the randomised playlist*/
    printf("A random playlist has been created for you:\n\n");
    i = 0;
    /*The loop will keep occuring until the playlist is around 1 hour, OR (detailed below) no songs are remaining to be printed.*/
    while(minutes < 60)
        {
            /*Variables to be reset at the beginning of each loop*/
            /*Error is used as a check to ensure all conditions are met before printing the song. If Error is not 0, the song will not print and the loop will run again.*/
            error = 0;
            temp = 0;
            check2 = 0;
            ran = rand() % songs;
            temp = ran;
            /*Goes through the loop of saved songs(explained below) and if ran matches one of the saved numbers, it will increment error.*/
            for (int j = 0; j < i; j++) 
                {
                    if (ran == songtracker[j]) 
                    {
                        error++;
                    }
                }
            /*The program will check the last printed song and if they are by the same artist, it will stop a "triple play" from occuring.*/
            check2 = strcmp(playlist[ran].artist, playlist[songtracker[i-1]].artist);
            if(check2 = 0)
            {
                error++;
            }
            /*If all the conditions are satisfied, the song will be printed.*/
            if(error < 1)
                {

                    printf("%s: %s (%s\n", playlist[ran].artist, playlist[ran].title, playlist[ran].length);
                    /*The program checks the duration, so that it can correctly add the time to overall duration.*/
                    size = strlen(playlist[ran].length);
                    /*The duration of the song is converted from char to int and added to minutes and seconds.*/
                    if(size == 6)
                    {
                        minutes = minutes + (playlist[ran].length[0] - '0');
                        seconds = seconds + ((playlist[ran].length[2] - '0') * 10);
                        seconds = seconds + (playlist[ran].length[3] - '0');
                    }
                    else if(size == 7)
                    {
                        minutes = minutes + ((playlist[ran].length[0] - '0') * 10);
                        minutes = minutes + (playlist[ran].length[1] - '0');
                        seconds = seconds + ((playlist[ran].length[3] - '0') * 10);
                        seconds = seconds + (playlist[ran].length[4] - '0');  
                    }
                    /*The song is added to this array to ensure it is not printed again*/
                    songtracker[i] = temp;
                    i++;
                }
            /*If seconds goes over 60, 1 will be added to minutes.*/
            if(seconds >= 60)
                {
                    seconds = seconds - 60;
                    minutes++;
                }
            /*If no songs are remaining, the program will break the loop and print the duration of whatever has been printed.*/
            if(i == songs)
            {
                break;
            }
               
         }
         /*One final check of seconds before printing to ensure there isn't more than 60 seconds*/
         if(seconds >= 60)
                {
                    seconds = seconds - 60;
                    minutes++;
                }     
    /*The duration of the playlist will be printed, based on how many seconds are remaining*/
    if(seconds < 10)
        {
            printf("Total playlist time: %d:0%d\n", minutes, seconds);
        }
    else
        {
            printf("Total playlist time: %d:%d\n", minutes, seconds);
        }
    /*The memory allocated for playlist and artistes is freed and the program ends.*/
    free(playlist);
    free(artistes);
    return 0;
}