#include <iostream>
using namespace std;
#include "LeagueManagementSystem.h"
int main() {


    //TEST CASE 1     // NO LEAK, CORRECT OUTPUT ( mostly), NO ERROR (mostly)

    /*
    LeagueManagementSystem LMS;
    LMS.showAllTeams();
    cout << endl;

    LMS.addTeam( "Fenerbahce", 1907 );
    LMS.addTeam( "Tofas", 1957 );
    LMS.addTeam( "Anadolu Efes", 1951 );
    LMS.removeTeam( "Tofas" );
    LMS.addTeam( "Darussafaka", 1951 );
    LMS.addTeam( "Fenerbahce", 1907 );
    LMS.removeTeam( "Tofas" );
    cout << endl;
    LMS.addPlayer( "Fenerbahce", "Melih Mahmutoglu", 10, 2000000 );
    LMS.addPlayer( "Fenerbahce", "Sehmus Hazer", 2, 1000000 );
    LMS.addPlayer( "Darussafaka", "Ercan Osmani", 6, 1000000 );
    LMS.addPlayer( "Anadolu Efes", "Dogus Balbay", 4, 1000000 );
    LMS.addPlayer( "Anadolu Efes", "Bugrahan Tuncer", 10, 1500000 );
    LMS.removePlayer( "Darussafaka", "Ercan Osmani" );
    cout << endl;
    LMS.addPlayer( "Fenerbahce", "Stephen Curry", 10, 10000000 );
    LMS.addPlayer( "Karsiyaka", "Metecan Birsen", 1, 1000000 );
    LMS.addTeam( "Karsiyaka", 1912 );
    LMS.addPlayer( "Karsiyaka", "Metecan Birsen", 1, 1000000 );
    LMS.removePlayer( "Tofas", "Melih Mahmutoglu" );
    LMS.removePlayer( "Fenerbahce", "Bugrahan Tuncer" );
    LMS.transferPlayer( "Metecan Birsen", "Karsiyaka", "Fenerbahce" );
    LMS.transferPlayer( "Lebron James", "Los Angeles Lakers", "Fenerbahce" );
    LMS.transferPlayer( "Michael Jordan", "Darussafaka", "Fenerbahce" );
    LMS.transferPlayer( "Bugrahan Tuncer", "Anadolu Efes", "Fenerbahce" );
    cout << endl;
    LMS.showAllTeams();
    cout << endl;
    LMS.showTeam( "Fenerbahce" );
    cout << endl;
    LMS.showTeam( "Boston Celtics" );
    cout << endl;
    LMS.showPlayer( "Melih Mahmutoglu" );
    cout << endl;
    LMS.showPlayer( "Furkan Korkmaz" );
    */

    // TEST CASE 2    // NO ERROR (mostly), CORRECT OUTPUT (mostly), NO MEMORY LEAK, Team deconstructor has been changed. MISMATCHED DELETE ERROR, //SIGTRAP (??)

    /*
    LeagueManagementSystem LMS;

    LMS.addTeam( "t1", 11 );
    LMS.addTeam( "t2", 12 );
    LMS.showAllTeams();
    cout << endl;
    LMS.removeTeam( "t2" );
    LMS.addPlayer( "t1", "p1", 1, 1 );
    LMS.addPlayer( "t1", "p2", 2, 2 );
    LMS.showTeam("t1");
    cout << endl;
    LMS.removePlayer("t1", "p2");
    LMS.showTeam("t1");
    */

    // TEST CASE 3 // CORRECT OUTPUT(mostly), NO ERROR(mostly), , NO LEAK  MISMATCHED DELETE ERROR,

    /*
    LeagueManagementSystem LMS;

    LMS.removeTeam("Fenerbahce");
    LMS.transferPlayer("Sehmus Hazer", "Fenerbahce", "Los Angeles Lakers");
    LMS.addPlayer("Fenerbahce","Sehmus Hazer", 2, 30000);
    LMS.addTeam("Fenerbahce",1907);
    LMS.transferPlayer("Sehmus Hazer", "Fenerbahce", "Los Angeles Lakers");
    LMS.showAllTeams();
    LMS.showPlayer("Sehmus Hazer");
    LMS.addPlayer("Fenerbahce", "Sehmus Hazer", 2, 50000);   // LMS 174
    LMS.showAllTeams();
    LMS.addTeam("Los Angeles Lakers", 2020);   // LMS 42
    LMS.transferPlayer("Sehmus Hazer", "Galatasaray", "New York Knicks");
    LMS.transferPlayer("Sehmus Hazer", "Galatasaray", "Los Angeles Lakers");
    LMS.transferPlayer("Sehmus Hazer", "Fenerbahce", "New York Knicks");
    LMS.transferPlayer("Sehmus Hazer", "Fenerbahce", "Los Angeles Lakers");  //LMS 438
    LMS.showTeam("Fenerbahce");
    LMS.showTeam("Los Angeles Lakers");
    LMS.removeTeam("Fenerbahce");   // LMS 119    // LMS 133
    LMS.addTeam("Konyaspor", 1931);   // LMS 42      // LMS 56
    LMS.addTeam("Alba Berlin", 1998);    // LMS 42    // LMS 56
    LMS.removePlayer("Alba Berlin","Maodo Lo");
    LMS.removePlayer("Konyaspor","Can Altintig");
    LMS.showAllTeams();
    LMS.addPlayer("Alba Berlin", "Maodo Lo", 4, 250000);
    LMS.addPlayer("Konyaspor", "Can Altintig", 5, 150000);   // LMS 174
    LMS.showPlayer("Maodo Lo");
    LMS.showPlayer("Vasa Micic");
    LMS.removePlayer("Alba Berlin","Maodo Lo");
    LMS.showAllTeams();
    LMS.showTeam("Konyaspor");
    LMS.addTeam("PAOK", 1942);   // LMS 56    // LMS 42
    LMS.addPlayer("PAOK","Onuralp Bitim", 10, 345000 );
    LMS.transferPlayer("Onuralp Bitim", "PAOK", "Los Angeles Lakers");
    LMS.removeTeam("Los Angeles Lakers");    // LMS 119
    LMS.removeTeam("Konyaspor");
    LMS.removeTeam("Alba Berlin");
    LMS.removeTeam("PAOK");
    LMS.showAllTeams();
    */

    //TEST CASE 4    //

    /*

    LeagueManagementSystem LMS;

    //Simple Transfer Check
    LMS.removeTeam("Fenerbahce");
    LMS.addTeam("Fenerbahce", -1);
    LMS.removeTeam("Fenerbahce");
    LMS.removeTeam("Fenerbahce");


    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);

    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showTeam("t2");

    LMS.removePlayer("t1", "p1");
    LMS.addPlayer("t2", "p3", 1,1);

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Multiple Transfers

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addTeam("t3", 12);


    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 2);
    LMS.addPlayer("t1", "p3", 3, 3);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t2");

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t2");

    LMS.transferPlayer("p1", "t2", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t3");

    LMS.transferPlayer("p1", "t2", "t2");
    LMS.transferPlayer("p2", "t2", "t3");
    LMS.transferPlayer("p3", "t2", "t2");

    LMS.transferPlayer("p1", "t2", "t3");
    LMS.transferPlayer("p2", "t2", "t3");
    LMS.transferPlayer("p3", "t2", "t3");

    LMS.transferPlayer("p1", "t3", "t1");
    LMS.transferPlayer("p2", "t3", "t2");
    LMS.transferPlayer("p3", "t3", "t1");

    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");

    LMS.addTeam("t4", 13);
    LMS.showTeam("t4");
    LMS.addPlayer("t4", "p4", 4, 4);
    LMS.showTeam("t4");
    LMS.showPlayer("p4");
    LMS.transferPlayer("p4", "t4", "t1");
    LMS.showTeam("t4");
    LMS.showPlayer("p4");
    LMS.removeTeam("t4");
    LMS.showTeam("t4");
    LMS.showPlayer("p4");

    LMS.removeTeam("t2");

    LMS.transferPlayer("p2", "t2", "t1");
    LMS.showPlayer("p2");

    LMS.removePlayer("t1", "p1");
    LMS.removePlayer("t1", "p2");
    LMS.removePlayer("t1", "p3");

    LMS.addPlayer("t1", "p11", 1, 1);
    LMS.addPlayer("t1", "p12", 2, 2);
    LMS.addPlayer("t1", "p13", 3, 3);

    LMS.addPlayer("t2", "p21", 1, 1);
    LMS.addPlayer("t2", "p22", 2, 2);
    LMS.addPlayer("t2", "p23", 3, 3);

    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.showTeam("t1");
    LMS.showTeam("t2");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Transfer Cycle

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addTeam("t3", 13);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 1);
    LMS.addPlayer("t2", "p3", 2, 1);
    LMS.addPlayer("t3", "p4", 2, 1);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t2", "t3");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t3", "t1");
    LMS.showPlayer("p1");
    LMS.showAllTeams();

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Jersey
    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t2", "p2", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");

    LMS.showPlayer("p1");

    LMS.removePlayer("t2", "p2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.removePlayer("t2", "p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Depart team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t1");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t1", 11);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    cout<<endl;

    // Arrive team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t2", 12);
    LMS.transferPlayer("p1", "t1", "t2");

     */


    // TEST CASE 5

    /*
    LeagueManagementSystem LMS;

    //Simple Transfer Check
    LMS.removeTeam("Fenerbahçe");
    LMS.addTeam("Fenerbahçe", -1);
    LMS.removeTeam("Fenerbahçe");
    LMS.removeTeam("Fenerbahçe");


    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);

    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showTeam("t2");

    LMS.removePlayer("t1", "p1");
    LMS.addPlayer("t2", "p3", 1,1);

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Multiple Transfers

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addTeam("t3", 12);


    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 2);
    LMS.addPlayer("t1", "p3", 3, 3);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t2");

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t2");

    LMS.transferPlayer("p1", "t2", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t3");

    LMS.transferPlayer("p1", "t2", "t2");
    LMS.transferPlayer("p2", "t2", "t3");
    LMS.transferPlayer("p3", "t2", "t2");

    LMS.transferPlayer("p1", "t2", "t3");
    LMS.transferPlayer("p2", "t2", "t3");
    LMS.transferPlayer("p3", "t2", "t3");

    LMS.transferPlayer("p1", "t3", "t1");
    LMS.transferPlayer("p2", "t3", "t2");
    LMS.transferPlayer("p3", "t3", "t1");

    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p2", "t2", "t1");
    LMS.transferPlayer("p2", "t1", "t2");

    LMS.addTeam("t4", 13);
    LMS.showTeam("t4");
    LMS.addPlayer("t4", "p5", 4, 4);
    LMS.showTeam("t4");
    LMS.showPlayer("p5");
    LMS.transferPlayer("p5", "t4", "t1");
    LMS.showTeam("t4");
    LMS.showPlayer("p5");
    LMS.removeTeam("t4");
    LMS.showTeam("t4");
    LMS.showPlayer("p5");

    LMS.removeTeam("t2");

    LMS.transferPlayer("p2", "t2", "t1");
    LMS.showPlayer("p2");

    LMS.removePlayer("t1", "p1");
    LMS.removePlayer("t1", "p2");
    LMS.removePlayer("t1", "p3");

    LMS.addPlayer("t1", "p11", 1, 1);
    LMS.addPlayer("t1", "p12", 2, 2);
    LMS.addPlayer("t1", "p13", 3, 3);

    LMS.addPlayer("t2", "p21", 1, 1);
    LMS.addPlayer("t2", "p22", 2, 2);
    LMS.addPlayer("t2", "p23", 3, 3);

    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.showTeam("t1");
    LMS.showTeam("t2");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Transfer Cycle

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addTeam("t3", 13);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 1);
    LMS.addPlayer("t2", "p3", 2, 1);
    LMS.addPlayer("t3", "p4", 2, 1);

    LMS.showAllTeams();

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t2", "t3");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t3", "t1");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t1", "t10");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t1", "t3");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t3", "t2");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t2", "t3");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t5", "t3");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t3", "t2");
    LMS.showPlayer("p1");
    LMS.showAllTeams();

    LMS.addTeam("t10", 10);
    LMS.addTeam("t11", 10);
    LMS.addTeam("t12", 10);
    LMS.addTeam("t13", 10);
    LMS.addTeam("t14", 10);
    LMS.addTeam("t15", 15);

    LMS.addPlayer("t10", "p10", 10, 10);
    LMS.addPlayer("t10", "p11", 10, 100);
    LMS.addPlayer("t10", "p12", 12, 1000);
    LMS.addPlayer("t10", "p13", 13, 10000);
    LMS.addPlayer("t10", "p14", 14, 100000);
    LMS.addPlayer("t10", "p15", 14, 100);
    LMS.addPlayer("t10", "p16", 16, 10);
    LMS.addPlayer("t10", "p17", 17, 10);
    LMS.addPlayer("t10", "p18", 18, 10);

    LMS.addPlayer("t10", "p11", 11, 100);
    LMS.addPlayer("t10", "p15", 15, 100);



    LMS.transferPlayer("p10", "t10", "t11");
    LMS.transferPlayer("p11", "t10", "t11");
    LMS.transferPlayer("p12", "t10", "t11");
    LMS.transferPlayer("p13", "t10", "t11");
    LMS.transferPlayer("p14", "t10", "t11");
    LMS.transferPlayer("p15", "t10", "t11");
    LMS.transferPlayer("p16", "t10", "t11");
    LMS.transferPlayer("p17", "t10", "t11");
    LMS.transferPlayer("p18", "t10", "t11");
    LMS.transferPlayer("p19", "t10", "t11");


    LMS.addPlayer("t11", "p19", 19, 100);
    LMS.transferPlayer("p10", "t11", "t12");
    LMS.transferPlayer("p11", "t11", "t12");
    LMS.transferPlayer("p12", "t11", "t12");
    LMS.transferPlayer("p13", "t11", "t12");
    LMS.transferPlayer("p14", "t11", "t12");
    LMS.addPlayer("t11", "p20", 20, 100);
    LMS.transferPlayer("p15", "t11", "t12");
    LMS.transferPlayer("p16", "t11", "t12");
    LMS.transferPlayer("p17", "t11", "t12");
    LMS.transferPlayer("p18", "t11", "t12");
    LMS.transferPlayer("p19", "t11", "t12");
    LMS.addPlayer("t11", "p21", 21, 100);
    LMS.showTeam("t12");


    LMS.transferPlayer("p13", "t12", "t13");
    LMS.transferPlayer("p13", "t13", "t12");
    LMS.transferPlayer("p13", "t12", "t13");
    LMS.transferPlayer("p13", "t13", "t12");
    LMS.transferPlayer("p13", "t12", "t13");
    LMS.transferPlayer("p13", "t13", "t12");
    LMS.showTeam("t12");

    LMS.showAllTeams();




    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Jersey
    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t2", "p2", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");

    LMS.showPlayer("p1");

    LMS.removePlayer("t2", "p2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.removePlayer("t2", "p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Depart team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t1");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t1", 11);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    cout<<endl;

    // Arrive team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t2", 12);
    LMS.transferPlayer("p1", "t1", "t2");

    */

    // TEST CASE 6

    LeagueManagementSystem LMS;


    //Simple Transfer Check
    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);

    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showTeam("t2");

    LMS.removePlayer("t1", "p1");
    LMS.addPlayer("t2", "p3", 1,1);

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Multiple Transfers

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);

    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 2);
    LMS.addPlayer("t1", "p3", 3, 3);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t2");

    LMS.removePlayer("t1", "p1");
    LMS.removePlayer("t1", "p2");
    LMS.removePlayer("t1", "p3");

    LMS.addPlayer("t1", "p11", 1, 1);
    LMS.addPlayer("t1", "p12", 2, 2);
    LMS.addPlayer("t1", "p13", 3, 3);

    LMS.addPlayer("t2", "p21", 1, 1);
    LMS.addPlayer("t2", "p22", 2, 2);
    LMS.addPlayer("t2", "p23", 3, 3);

    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.showTeam("t1");
    LMS.showTeam("t2");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Transfer Cycle

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addTeam("t3", 13);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 1);
    LMS.addPlayer("t2", "p3", 2, 1);
    LMS.addPlayer("t3", "p4", 2, 1);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t2", "t3");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t3", "t1");
    LMS.showPlayer("p1");
    LMS.showAllTeams();

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Jersey
    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t2", "p2", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");

    LMS.showPlayer("p1");

    LMS.removePlayer("t2", "p2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.removePlayer("t2", "p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Depart team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t1");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t1", 11);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    cout<<endl;

    // Arrive team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t2", 12);
    LMS.transferPlayer("p1", "t1", "t2");



    return 0;
}