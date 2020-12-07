Action()
{
lr_start_transaction("05_ViewItinerary");

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
	
lr_think_time(11);

lr_start_transaction("Login");

web_reg_find("Text=to the Web Tours reservation pages",LAST);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=login.x", "Value=44", ENDITEM, 
		"Name=login.y", "Value=15", ENDITEM, 
		LAST);
	lr_end_transaction("Login",LR_AUTO);
	
	lr_start_transaction("ViewTicket");
	
	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);
lr_end_transaction("ViewTicket", LR_AUTO);

	lr_think_time(4);
	lr_start_transaction("Logout");
	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t4.inf", 
		LAST);

lr_end_transaction("Logout", LR_AUTO);
lr_end_transaction("05_ViewItinerary", LR_AUTO);
	return 0;
}