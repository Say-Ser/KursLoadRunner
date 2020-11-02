Action()
{
	lr_start_transaction("ReserveRoundtripticket");
	
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

	lr_think_time(19);
	
	lr_end_transaction("WebTours", LR_AUTO);
	
lr_start_transaction("Login");

web_reg_find("Text=Error","Fail=Found",LAST); 

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=major", ENDITEM, 
		"Name=password", "Value=pain", ENDITEM, 
		"Name=login.x", "Value=75", ENDITEM, 
		"Name=login.y", "Value=1", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(21);

lr_start_transaction("SearchReis");

web_reg_find("Text=Error","Fail=Found",LAST);
	
/*Correlation comment - Do not change!  Original value='07/09/2020' Name ='departDate' Type ='RecordReplay'*/
	web_reg_save_param_attrib(
		"ParamName=departDate",
		"TagName=input",
		"Extract=value",
		"Name=departDate",
		"Type=text",
		SEARCH_FILTERS,
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_think_time(11);

	web_submit_form("reservations.pl",
		"Snapshot=t4.inf",
		ITEMDATA,
		"Name=depart", "Value=Denver", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value=Paris", ENDITEM,
		"Name=returnDate", "Value=07/11/2020", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=roundtrip", "Value=on", ENDITEM,
		"Name=seatPref", "Value=None", ENDITEM,
		"Name=seatType", "Value=Business", ENDITEM,
		"Name=findFlights.x", "Value=60", ENDITEM,
		"Name=findFlights.y", "Value=9", ENDITEM,
		LAST);

	lr_end_transaction("SearchReis", LR_AUTO);

	
	lr_think_time(4);
	
lr_start_transaction("ChousReis");

	web_submit_form("reservations.pl_2",
		"Snapshot=t5.inf",
		ITEMDATA,
		"Name=outboundFlight", "Value=040;508;{departDate}", ENDITEM,
		"Name=returnFlight", "Value=402;481;07/11/2020", ENDITEM,
		"Name=reserveFlights.x", "Value=52", ENDITEM,
		"Name=reserveFlights.y", "Value=7", ENDITEM,
		LAST);
lr_end_transaction("ChousReis", LR_AUTO);

	lr_start_transaction("InputPassData");
	
	web_reg_find("Text=Error","Fail=Found",LAST);
	
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
		"Name=buyFlights.x", "Value=80", ENDITEM, 
		"Name=buyFlights.y", "Value=3", ENDITEM, 
		LAST);

	lr_end_transaction("InputPassData", LR_AUTO);
	
	lr_start_transaction("Logout");
	
	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t7.inf", 
		LAST);
	
	lr_end_transaction("Logout", LR_AUTO);

	lr_end_transaction("ReserveRoundtripticket", LR_AUTO);

	return 0;
}