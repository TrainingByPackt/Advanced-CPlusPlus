#include"Misc.h"

int main(){

    App app;
    app.connectDB("dbname","dbuser", "dbpasswd");
    string ip = app.getDBResult("dummy"); 
    // DB query to get Webserver IP
    // Similarly some miscellaneous activities to get configuratio information
    // Like querying DB to get correct username/passwd to connect to WebServer.. 

    // After getting IP from DB, check if the IP is valid..
    //app.checkValidIp(ip);

    // Now conect to webserver with parameters extracted from DB. 
    app.connectWeb("webname","user", "passwd");

    // Now run the App, like sending some request to webserver, 
    // getting result and doing activity with received data. 
    app.run();

    return 0;
}
