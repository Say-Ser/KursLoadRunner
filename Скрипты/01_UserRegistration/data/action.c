Action()
{

	web_url("WebTours", 
		"URL=http://localhost/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(18);

	web_link("sign up now", 
		"Text=sign up now", 
		"Snapshot=t5.inf", 
		LAST);

	lr_think_time(41);

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

	lr_think_time(6);

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t7.inf", 
		LAST);

	lr_think_time(4);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t8.inf", 
		LAST);

	return 0;
}