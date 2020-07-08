Action()
{
	lr_start_transaction("UserRegestration");

	
lr_start_transaction("WebTours");

	web_url("WebTours", 
		"URL=http://localhost/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
lr_end_transaction("WebTours", LR_AUTO);

	lr_think_time(18);
	
lr_start_transaction("GoToSingUp");

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t5.inf", 
		LAST);
lr_end_transaction("GoToSingUp", LR_AUTO);

	lr_think_time(41);

	lr_start_transaction("InputData");

	web_submit_form("login.pl", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=username", "Value=Major", ENDITEM, 
		"Name=password", "Value=pain", ENDITEM, 
		"Name=passwordConfirm", "Value=pain", ENDITEM, 
		"Name=firstName", "Value=", ENDITEM, 
		"Name=lastName", "Value=", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=22", ENDITEM, 
		"Name=register.y", "Value=6", ENDITEM, 
		LAST);
	
	lr_end_transaction("InputData", LR_AUTO);

	
lr_end_transaction("UserRegestration", LR_AUTO);

	return 0;
}