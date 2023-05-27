endTime = time(NULL);
double elapsedTime = difftime(endTime, startTime);
P.timer=P.timer + elapsedTime; 
if (checkTreasure(P)==0 && number_of_players_who_played==number_of_players){
    number_of_players_who_played=0;
