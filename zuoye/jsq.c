#if 1
#define SERVER_NAME cgiServerName
#endif
#define SAVED_ENVIRONMENT "/tmp/cgicsave.env"

#include <stdio.h>
#include "cgic.h"
#include <string.h>
#include <stdlib.h>

void HandleSubmit();
void ShowForm();
void CookieSet();
void Name();
void Address();
void Hungry();
void Temperature();
void Frogs();
void Color();
void Flavors();
void NonExButtons();
void RadioButtons();
void File();
void Entries();
void Cookies();
void LoadEnvironment();
void SaveEnvironment();


int cgiMain() {
#ifdef DEBUG
	LoadEnvironment();
#endif
	if (cgiFormSubmitClicked("loadenvironment") == cgiFormSuccess) {
		LoadEnvironment();
	}
  CookieSet();
	cgiHeaderContentType("text/html");
	fprintf(cgiOut, "<HTML><HEAD>\n");
	fprintf(cgiOut, "<TITLE>cgic test</TITLE></HEAD>\n");
	fprintf(cgiOut, "<BODY><H1>cgic test</H1>\n");
	if ((cgiFormSubmitClicked("testcgic") == cgiFormSuccess) ||
		cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess)
	{
		HandleSubmit();
		fprintf(cgiOut, "<hr>\n");
	}
	ShowForm();
	fprintf(cgiOut, "</BODY></HTML>\n");
	return 0;
}

void HandleSubmit()
{
	Name();

	if (cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess) {
		SaveEnvironment();
	}

void Name() {
	char name[81];
	cgiFormStringNoNewlines("name", name, 81);
	fprintf(cgiOut, "Name: ");
	cgiHtmlEscape(name);
	fprintf(cgiOut, "<BR>\n");
}

void Cookies()
{
	char **array, **arrayStep;
	char cname[1024], cvalue[1024];
	fprintf(cgiOut, "Cookies Submitted On This Call, With Values (Many Browsers NEVER Submit Cookies):<p>\n");
	if (cgiCookies(&array) != cgiFormSuccess) {
		return;
	}
	arrayStep = array;
	fprintf(cgiOut, "<table border=1>\n");
	fprintf(cgiOut, "<tr><th>Cookie<th>Value</tr>\n");
	while (*arrayStep) {
		char value[1024];
		fprintf(cgiOut, "<tr>");
		fprintf(cgiOut, "<td>");
		cgiHtmlEscape(*arrayStep);
		fprintf(cgiOut, "<td>");
		cgiCookieString(*arrayStep, value, sizeof(value));
		cgiHtmlEscape(value);
		fprintf(cgiOut, "\n");
		arrayStep++;
	}
	fprintf(cgiOut, "</table>\n");
	cgiFormString("cname", cname, sizeof(cname));
	cgiFormString("cvalue", cvalue, sizeof(cvalue));
	if (strlen(cname)) {
		fprintf(cgiOut, "New Cookie Set On This Call:<p>\n");
		fprintf(cgiOut, "Name: ");
		cgiHtmlEscape(cname);
		fprintf(cgiOut, "Value: ");
		cgiHtmlEscape(cvalue);
		fprintf(cgiOut, "<p>\n");
		fprintf(cgiOut, "If your browser accepts cookies (many do not), this new cookie should appear in the above list the next time the form is submitted.<p>\n");
	}
	cgiStringArrayFree(array);
}
void File()
{
	cgiFilePtr file;
	char name[1024];
	char contentType[1024];
	char buffer[1024];
	int size;
	int got;
	if (cgiFormFileName("file", name, sizeof(name)) != cgiFormSuccess) {
		printf("<p>No file was uploaded.<p>\n");
		return;
	}
  void ShowForm()
  {
  	fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads. -->");
  	fprintf(cgiOut, "<form method=\"POST\" enctype=\"multipart/form-data\" ");
  	fprintf(cgiOut, "	action=\"");
  	cgiValueEscape(cgiScriptName);
  	fprintf(cgiOut, "\">\n");
  	fprintf(cgiOut, "<p>\n");
  	fprintf(cgiOut, "Text Field containing Plaintext\n");
  	fprintf(cgiOut, "<p>\n");
  	fprintf(cgiOut, "<input type=\"text\" name=\"name\">\n");




















void CookieSet()
{
	char cname[1024];
	char cvalue[1024];

	cgiFormString("cname", cname, sizeof(cname));
	cgiFormString("cvalue", cvalue, sizeof(cvalue));
	if (strlen(cname)) {

		cgiHeaderCookieSetString(cname, cvalue,
			86400, cgiScriptName, SERVER_NAME);
	}
}

void LoadEnvironment()
{
	if (cgiReadEnvironment(SAVED_ENVIRONMENT) !=
		cgiEnvironmentSuccess)
	{
		cgiHeaderContentType("text/html");
		fprintf(cgiOut, "<head>Error</head>\n");
		fprintf(cgiOut, "<body><h1>Error</h1>\n");
		fprintf(cgiOut, "cgiReadEnvironment failed. Most "
			"likely you have not saved an environment "
			"yet.\n");
		exit(0);
	}

}

void SaveEnvironment()
{
	if (cgiWriteEnvironment(SAVED_ENVIRONMENT) !=
		cgiEnvironmentSuccess)
	{
		fprintf(cgiOut, "<p>cgiWriteEnvironment failed. Most "
			"likely %s is not a valid path or is not "
			"writable by the user that the CGI program "
			"is running as.<p>\n", SAVED_ENVIRONMENT);
	} else
  {
		fprintf(cgiOut, "<p>Environment saved. Click this button "
			"to restore it, playing back exactly the same "
			"scenario: "
			"<form method=POST action=\"");
		cgiValueEscape(cgiScriptName);
		fprintf(cgiOut, "\">"
			"<input type=\"submit\" "
			"value=\"Load Environment\" "
			"name=\"loadenvironment\"></form><p>\n");
	}
}
