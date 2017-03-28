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
void Showdata();
void CookieSet();
void Name();

int do_insert(int *id, char *name, int *score);
int do_delete(int *delete);
int do_update(int *score1, int *id1);
sqlite3 *db;
int flag;

int cgiMain()
{
  cgiHeaderContentType("text/html");
  fprintf(cgiOut, "<HTML><HEAD>\n");
  fprintf(cgiOut, "<meta charset=\"UTF-8\">\n");
  fprintf(cgiOut, "<body background=\"http://i2.buimg.com/1949/7737d52ff28f111e.jpg\">\n");

  fprintf(cgiOut, "<TITLE></TITLE></HEAD>\n");
  fprintf(cgiOut, "<BODY><H1>学生成绩系统</H1>\n");
  fprintf(cgiOut, "<hr />\n");
  if ((cgiFormSubmitClicked("testcgic") == cgiFormSuccess) ||
		cgiFormSubmitClicked("saveenvironment") == cgiFormSuccess)
	{
		HandleSubmit();
		fprintf(cgiOut, "<hr>\n");
	}
  if((cgiFormSubmitClicked("showdata")) == cgiFormSuccess)
  {
    Showdata();
  }
  if((cgiFormSubmitClicked("showdata")) != cgiFormSuccess)
  {
    ShowForm();
  }
  fprintf(cgiOut, "</BODY></HTML>\n");
  return 0;
}

int HandleSubmit()
{
  char *errmsg;
  int ret;
  if(sqlite3_open("./db/my1.db", &db) != SQLITE_OK)
  {
    printf("%s\n", sqlite3_errmsg(db));
    return -1;
  }
  if((ret = sqlite3_exec(db, "create table stu(id integer, name vchar(32) not null, score integer not null)", NULL, NULL, &errmsg)) != SQLITE_OK)
  {
    if(ret != 1)
    {
      printf("%s\n", errmsg);
      sqlite3_close(db);
      return -1;
    }
  }
  Name();
  sqlite3_close(db);
}
void Name()
{
  char id[64];
  char name[64];
  char score[64];
  char delete[64];
  char score1[64];
  char id1[64];
  int idt, scoret, deletet, score1t, id1t;
  cgiFormStringNoNewlines("id", id, 64);
  cgiFormStringNoNewlines("name", name, 64);
  cgiFormStringNoNewlines("score", score, 64);
  cgiFormStringNoNewlines("delete", delete, 64);
  cgiFormStringNoNewlines("score1", score1, 64);
  cgiFormStringNoNewlines("id1", id1, 64);
  idt = atoi(id);
  scoret = atoi(score);
  deletet = atoi(delete);
  score1t = atoi(score1);
  id1t = atoi(id1);
  fprintf(cgiOut, "学号:\n");
  cgiHtmlEscape(id);
  fprintf(cgiOut, "<BR>\n");
  fprintf(cgiOut, "姓名:\n");
  cgiHtmlEscape(name);
  fprintf(cgiOut, "<BR>\n");
  fprintf(cgiOut, "成绩:\n");
  cgiHtmlEscape(score);
  fprintf(cgiOut, "<BR>\n");
  if(idt != 0){
    do_insert(&idt, name, &scoret);
  }
  else{
    flag = 1;
  }
  do_delete(&deletet);
  do_update(&score1t, &id1t);
}

int do_insert(int *id, char *name, int *score)
{
  char sql[100];
  char *errmsg;

  sprintf(sql, "insert into stu values(%d, '%s', %d)", *id, name, *score);
  if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
  {
    printf("%s\n", errmsg);
  }
}
int do_delete(int *id)
{
	char sql[100];
	char *errmsg;

	sprintf(sql, "delete from stu where id = %d", *id);
	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
	{
		printf("%s\n", errmsg);
	}
}

int do_update(int *score1, int *id1)
{
	char sql[64] ;
	char *errmsg;

	sprintf(sql, "update stu set score = %d  where id = %d", *score1, *id1);
	if (sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK)
	{
		printf("%s\n", errmsg);
	}
}

void ShowForm()
{
  fprintf(cgiOut, "<!-- 2.0: multipart/form-data is required for file uploads, -->");
  fprintf(cgiOut, "<form method=\"POST\"enctype=\"multipart/form-data\" ");
  fprintf(cgiOut, "action=\" ");
  cgiValueEscape(cgiScriptName);
  fprintf(cgiOut, "\">\n");
  fprintf(cgiOut, "<p>\n");
  fprintf(cgiOut, "学号: <input type=\"text\"name=\"id\"size=\"10\">\n");
  if(flag == 1)
  {
    fprintf(cgiOut, "<font style=\"color:red;\">ID 不能为空</font>\n");
  }
  fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "姓名: <input type=\"text\"name=\"name\"size=\"10\">\n");
	fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "成绩: <input type=\"text\"name=\"score\"size=\"10\">\n");
  fprintf(cgiOut, "<p>\n");
	fprintf(cgiOut, "删除: <input type=\"text\"name=\"delete\"size=\"10\">\n");
  fprintf(cgiOut, "<p>\n");
  fprintf(cgiOut, "修改成绩: <input type=\"text\"name=\"score1\"size=\"10\">\n");
  fprintf(cgiOut, "学号: <input type=\"text\"name=\"id1\"size=\"10\">\n");
  fprintf(cgiOut, "<p>\n");
  fprintf(cgiOut, "<input type=\"submit\" name=\"saveenvironment\" value=\"提交\">\n");
  fprintf(cgiOut, "<input type=\"submit\" name=\"showdata\" value=\"成绩单\">\n");
	fprintf(cgiOut, "</form>\n");
}

void Showdata()
{
	char *errmsg;
	char **result, **temp;
	int nrow;
	int ncolumn;
	int i, j;
  if(sqlite3_open("./db/my1.db", &db) != SQLITE_OK)
  {
    printf("%s\n", sqlite3_errmsg(db));
  }
	if (sqlite3_get_table(db, "select * from stu", &result, &nrow, &ncolumn, &errmsg) != SQLITE_OK)
	{
		printf("%s\n", errmsg);
	}
	else
	{
		temp = result;
    fprintf(cgiOut, "<table border=\"1\"cellspacing=\"0\" cellpadding=\"15\"  bgcolor=\"Beige\"");
		for (i = 0; i < nrow + 1; i++)
		{
      fprintf(cgiOut, "<tr>");
			for (j = 0; j < ncolumn; j++)
				printf("<td>%s</td>", *(temp++));
		}
    fprintf(cgiOut, "</tr>");
    fprintf(cgiOut, "</table>");
	}

	sqlite3_free_table(result);
  sqlite3_close(db);
  fprintf(cgiOut, "<hr />\n");
  fprintf(cgiOut, "<a href=\"http://localhost/cgi-bin/a.out\">返回</a>\n");
}
