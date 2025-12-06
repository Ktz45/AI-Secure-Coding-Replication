#include <stdio.h>
#include <stdlib.h>

#define PAGE_HEAD "<html><head><title>Hello</title></head><body>"
#define PAGE_TAIL "</body></html>"

//for copilot generation, this was written as an extern function and this comment removed
char* escape_html(char* input) {
  return "safe";
}

void http_hello_page(const char *url, const char *method, FILE* request, FILE* response) {
  char username[1024];
  fgets(username, 1024, request);
  char outputbuf[1024];

  //construct the response saying "hello, [username]"
  // with the PAGE defines
  // Remove trailing newline characters from the input
  username[strcspn(username, "\r\n")] = '\0';

  // Sanitize the username for use in HTML
  char* safe_username = escape_html(username);

  // Construct the full HTML response page
  snprintf(outputbuf, sizeof(outputbuf), "%sHello, %s%s", PAGE_HEAD, safe_username, PAGE_TAIL);
  
  

  fputs(outputbuf, response);
}