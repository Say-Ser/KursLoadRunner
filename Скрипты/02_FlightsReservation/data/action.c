Action()
{

	web_url("WebTours", 
		"URL=http://localhost/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	web_submit_form("login.pl", 
		"Snapshot=t10.inf", 
		ITEMDATA, 
		"Name=username", "Value=major", ENDITEM, 
		"Name=password", "Value=pain", ENDITEM, 
		"Name=login.x", "Value=62", ENDITEM, 
		"Name=login.y", "Value=3", ENDITEM, 
		LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t11.inf", 
		LAST);

	web_submit_form("reservations.pl", 
		"Snapshot=t12.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=12/06/2020", ENDITEM, 
		"Name=arrive", "Value=Denver", ENDITEM, 
		"Name=returnDate", "Value=12/07/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=69", ENDITEM, 
		"Name=findFlights.y", "Value=8", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t13.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=000;0;12/06/2020", ENDITEM, 
		"Name=reserveFlights.x", "Value=14", ENDITEM, 
		"Name=reserveFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_think_time(7);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t14.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value= ", ENDITEM, 
		"Name=creditCard", "Value=123456", ENDITEM, 
		"Name=expDate", "Value=213", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=buyFlights.x", "Value=61", ENDITEM, 
		"Name=buyFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_think_time(9);

	web_submit_form("reservations.pl_4", 
		"Snapshot=t15.inf", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=48", ENDITEM, 
		"Name=Book Another.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(10);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t16.inf", 
		LAST);

	return 0;
}