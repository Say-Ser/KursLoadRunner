Action()
{

	
lr_start_transaction("DeleteFlightsReservation");

	
lr_start_transaction("WebTours");

web_reg_find("Text=Error","Fail=Found",LAST);

	web_url("WebTours", 
		"URL=http://localhost/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
lr_end_transaction("WebTours", LR_AUTO);

	lr_think_time(10);

	
lr_start_transaction("LoginUser");

web_reg_find("Text=Error","Fail=Found",LAST);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=major", ENDITEM, 
		"Name=password", "Value=pain", ENDITEM, 
		"Name=login.x", "Value=52", ENDITEM, 
		"Name=login.y", "Value=5", ENDITEM, 
		LAST);

lr_end_transaction("LoginUser", LR_AUTO);

lr_start_transaction("DeleteItinerary");

web_reg_find("Text=Error","Fail=Found",LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(24);

	
web_submit_data("itinerary.pl", 
	    "Action=http://localhost/cgi-bin/itinerary.pl", 
	    "Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost/cgi-bin/itinerary.pl", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeAllFlights.x", "Value=73", ENDITEM, 
		"Name=removeAllFlights.y", "Value=15", ENDITEM, 
		LAST);
	
	
/*	web_submit_data("itinerary.pl", 
		"Action=http://localhost/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=128001120-1000193-\r\n", ENDITEM, 
		"Name=flightID", "Value=1280000-15-\r\n", ENDITEM, 
		"Name=flightID", "Value=128001500-261768-\r\n", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeAllFlights.x", "Value=49", ENDITEM, 
		"Name=removeAllFlights.y", "Value=11", ENDITEM, 
		LAST);
	*/
	
lr_end_transaction("DeleteItinerary", LR_AUTO);

lr_start_transaction("Logout");

web_reg_find("Text=Error","Fail=Found",LAST);

	web_url("welcome.pl", 
		"URL=http://localhost/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
		
lr_end_transaction("Logout", LR_AUTO);

lr_end_transaction("DeleteFlightsReservation", LR_AUTO);

	return 0;
}