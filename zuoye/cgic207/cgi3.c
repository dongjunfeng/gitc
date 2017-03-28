#if 1
#define SERVER_NAME cgiServerName
#endif
#define SAVED_ENVIRONMENT "/tmp/cgicsave.env"

#include <stdio.h>
#include "cgic.h"
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

int HandleSubmit();
void ShowForm();
void CookieSet();
void Name();
//void ID();
//void Score();
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
int do_insert(int *id, char *name, int *score);
sqlite3 *db;

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

int HandleSubmit()
{
  char *errmsg;
  int ret;

	if (sqlite3_open("./db/my.db", &db) != SQLITE_OK)
  {
    printf("%s\n", sqlite3_errmsg(db));
    return -1;
  }
  if((ret = sqlite3_exec(db, "create table stu(id integer, name vchar(32) not null,score integer not null)", NULL, NULL, &errmsg)) != SQLITE_OK)
  {
    if(ret != 1)
    {
      printf("%s\n", errmsg);
      sqlite3_close(db);
      return -1;
    }
  }
	Name();
	if (cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess) {
		SaveEnvironment();
	}
	sqlite3_close(db);
}
void Name() {
	char id[81];
	char name[241];
	char score[241];
	int idt;
	int scoret;
	cgiFormStringNoNewlines("id", id, 81);
	cgiFormStringNoNewlines("name", name, 241);
	cgiFormStringNoNewlines("score", score, 241);
	idt = atoi(id);
	scoret = atoi(score);
	cgiHtmlEscape(id);
	fprintf(cgiOut, "<BR>\n");

	cgiHtmlEscape(name);
	fprintf(cgiOut, "<BR>\n");

	cgiHtmlEscape(score);
	fprintf(cgiOut, "<BR>\n");

	do_insert(&idt, name, &scoret);
}

int do_insert(int *id, char *name, int *score)
{
  char sql[100];
  char *errmsg;
  sprintf(sql, "insert into stu values(%d, '%s', %d)", *id, name, *score);

  if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
  {
    printf("%s\n", errmsg);
    return -1;
  }
}

void ShowForm()
{
	fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads. -->");
	fprintf(cgiOut, "<form method=\"POST\" enctype=\"multipart/form-data\" ");
	fprintf(cgiOut, "	action=\"");
	cgiValueEscape(cgiScriptName);
	fprintf(cgiOut, "\">\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, " ID : <input type=\"text\"name=\"id\">\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "Name: <input type=\"text\"name=\"name\">\n");
	fprintf(cgiOut, "<p>\n");
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
	if (cgiWriteEnvironment(SAVED_ENVIRONMENT) != cgiEnvironmentSuccess)
	{
		fprintf(cgiOut, "<p>cgiWriteEnvironment failed. Most "
			"likely %s is not a valid path or is not "
			"writable by the user that the CGI program "
			"is running as.<p>\n", SAVED_ENVIRONMENT);
		}
	else
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
