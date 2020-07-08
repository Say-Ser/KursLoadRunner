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

	lr_think_time(9);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=major", ENDITEM, 
		"Name=password", "Value=pain", ENDITEM, 
		"Name=login.x", "Value=33", ENDITEM, 
		"Name=login.y", "Value=7", ENDITEM, 
		LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(13);

	web_submit_form("reservations.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=07/09/2020", ENDITEM, 
		"Name=arrive", "Value=London", ENDITEM, 
		"Name=returnDate", "Value=07/20/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=findFlights.x", "Value=49", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=022;600;07/09/2020", ENDITEM, 
		"Name=reserveFlights.x", "Value=70", ENDITEM, 
		"Name=reserveFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_think_time(4);

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
		"Name=buyFlights.x", "Value=58", ENDITEM, 
		"Name=buyFlights.y", "Value=1", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_4", 
		"Snapshot=t7.inf", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=57", ENDITEM, 
		"Name=Book Another.y", "Value=7", ENDITEM, 
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t8.inf", 
		LAST);

	return 0;
}