void resister_error_handler(void(*handler)(const char* msg));
void log_error(const char* msg);

static void (*s_handler)(const char*) = NULL;

void restister_error_handler(void(*handler)(const char* msg))
{
	s_handler = handler;
}

void log_error(const char* msg)
{
	if(s_handler != NULL){
		s_handler(msg);
	}
}

void simple_stderr_print(const char* msg)
{
	fputs(msg, stderr);
}

int main()
{
	...
	resister_error_handler(simple_stderr_print);
	
	if(denominator == 0){
		log_error("cannot dividy by zero");
		return FALSE;
	}
	...
}
