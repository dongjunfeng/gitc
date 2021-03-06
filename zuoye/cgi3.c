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
void Concent();
/*void Hungry();
void Temperature();
void Frogs();
void Color();
void Flavors();
void NonExButtons();
void RadioButtons();
void File();
void Entries();
void Cookies();*/
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
	fprintf(cgiOut, "<TITLE>Note</TITLE></HEAD>\n");
	fprintf(cgiOut, "<BODY><H1>Note</H1>\n");
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
	ID();
  Name();
	Score();
	if (cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess) {
		SaveEnvironment();
	}
}
void ID() {
	char id[81];
	cgiFormStringNoNewlines("id", id, 81);
	fprintf(cgiOut, "ID: ");
	cgiHtmlEscape(id);
	fprintf(cgiOut, "<BR>\n");
}
void Name()
{
	char name[241];
	cgiFormString("name", name, 241);
	fprintf(cgiOut, "Name: \n");
	cgiHtmlEscape(name);
	fprintf(cgiOut, "<BR>\n");
}
void Score()
{
	char score[241];
	cgiFormString("score", score, 241);
	fprintf(cgiOut, "Score: \n");
	cgiHtmlEscape(score);
	fprintf(cgiOut, "<BR>\n");
}
void ShowForm()
{
	fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads. -->");
	fprintf(cgiOut, "<form method=\"POST\" enctype=\"multipart/form-data\" ");
	fprintf(cgiOut, "	action=\"");
	cgiValueEscape(cgiScriptName);
	fprintf(cgiOut, "\">\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "ID: <input type=\"text\"name=\"id\">\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "Name: <input type=\"text\"name=\"name\">\n");
	fprintf(cgiOut, "Score: <input type=\"text\"name=\"score\">\n");
	/*fprintf(cgiOut, "concent<p>\n");
  fprintf(cgiOut, "<textarea NAME=\"concent\" ROWS=4 COLS=40>\n");

  fprintf(cgiOut, "</textarea>\n");*/
	fprintf(cgiOut, "<p>\n");
  fprintf(cgiOut, "<input type=\"submit\" name=\"saveenvironment\" value=\"Save Environment\">\n");
	fprintf(cgiOut, "</form>\n");
}
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
	}
}
