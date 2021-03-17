Action()
{

	
lr_start_transaction("03_DeleteFlightsReservation");

	
lr_start_transaction("WebTours");



web_reg_find("Text=Welcome to the Web Tours site.",
		LAST);
		
		

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

	
lr_start_transaction("Login");


	web_reg_find("Text=Welcome, <b>{Login}</b>, to the Web Tours reservation pages.", 
		LAST);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=52", ENDITEM, 
		"Name=login.y", "Value=5", ENDITEM, 
		LAST);

lr_end_transaction("Login", LR_AUTO);

lr_start_transaction("DeleteItinerary");

web_reg_find("Text=Itinerary", 		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(24);

	web_reg_find("Text=No flights have been reserved.", 		LAST);

	web_submit_form("itinerary.pl", 
		"Snapshot=t27.inf", 
		ITEMDATA, 
		"Name=1", "Value=<OFF>", ENDITEM,
		"Name=removeAllFlights.x", "Value=44", ENDITEM, 
		"Name=removeAllFlights.y", "Value=12", ENDITEM, 
		LAST);
	
lr_end_transaction("DeleteItinerary", LR_AUTO);

lr_start_transaction("Logout");

web_reg_find("Text=Welcome to the Web Tours site.", 
		LAST); 
		

	web_url("welcome.pl", 
		"URL=http://localhost/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
		
lr_end_transaction("Logout", LR_AUTO);

lr_end_transaction("03_DeleteFlightsReservation", LR_AUTO);

	return 0;
}