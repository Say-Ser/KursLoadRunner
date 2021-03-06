Action()
{
lr_start_transaction("02_FlightsReservation");
	
lr_start_transaction("WebTours");


web_reg_find("Text=Welcome to the Web Tours site.",
		LAST);
		
		
	web_url("WebTours", 
		"URL=http://localhost/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("WebTours", LR_AUTO);


	lr_think_time(9);

lr_start_transaction("Login");
	
	web_reg_find("Text=Welcome, <b>{Login}</b>, to the Web Tours reservation pages.", 
		LAST);
		
	web_submit_form("login.pl", 
		"Snapshot=t10.inf", 
		ITEMDATA, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=62", ENDITEM, 
		"Name=login.y", "Value=3", ENDITEM, 
		LAST);
lr_end_transaction("Login", LR_AUTO);

	lr_think_time(4);
	
lr_start_transaction("SearchReis");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t11.inf", 
		LAST);

/*Correlation comment - Do not change!  Original value='000;0;12/06/2020' Name ='outboundFlight' Type ='RecordReplay'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		LAST);

//web_reg_find("Text=Flight departing from <b>{arrive}</b> to <b>{depart}</b> on <b>{departDate}</b>", LAST);
	
web_submit_form("reservations.pl",
		"Snapshot=t12.inf", 
		ITEMDATA,
		"Name=depart", "Value={depart}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={arrive}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=roundtrip", "Value=<OFF>", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=49", ENDITEM,
		"Name=findFlights.y", "Value=11", ENDITEM,
		LAST);
lr_end_transaction("SearchReis", LR_AUTO);

lr_start_transaction("ChousReis");

web_reg_find("Text=Payment Details", 
		LAST);

	web_submit_form("reservations.pl_2",
		"Snapshot=t13.inf",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=reserveFlights.x", "Value=14", ENDITEM,
		"Name=reserveFlights.y", "Value=4", ENDITEM,
		LAST);

lr_end_transaction("ChousReis", LR_AUTO);

	lr_think_time(4);

	lr_start_transaction("InputPassData");
	
	web_reg_find("Text=Thank you for booking through Web Tours.", 
		LAST);
	
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
	
lr_end_transaction("InputPassData", LR_AUTO);

lr_start_transaction("Logout");

	web_reg_find("Text=Welcome to the Web Tours site.", 
		LAST); 
		
web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t15.inf", 
		LAST);
		
lr_end_transaction("Logout", LR_AUTO);

lr_end_transaction("02_FlightsReservation", LR_AUTO);


	return 0;
}