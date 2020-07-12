Action()
{

	web_url("WebTours", 
		"URL=http://localhost/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=major", ENDITEM, 
		"Name=password", "Value=pain", ENDITEM, 
		"Name=login.x", "Value=41", ENDITEM, 
		"Name=login.y", "Value=5", ENDITEM, 
		LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(10);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=07/13/2020", ENDITEM, 
		"Name=arrive", "Value=London", ENDITEM, 
		"Name=returnDate", "Value=07/14/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=45", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=020;338;07/13/2020", ENDITEM, 
		"Name=reserveFlights.x", "Value=58", ENDITEM, 
		"Name=reserveFlights.y", "Value=5", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value= ", ENDITEM, 
		"Name=creditCard", "Value=123456", ENDITEM, 
		"Name=expDate", "Value=213", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=buyFlights.x", "Value=40", ENDITEM, 
		"Name=buyFlights.y", "Value=6", ENDITEM, 
		LAST);

	return 0;
}