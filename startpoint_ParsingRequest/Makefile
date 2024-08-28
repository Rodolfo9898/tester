# Project Name
NAME = webserv

# Compiler and Flags
CCXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Valgrind
valgrind= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

# Directories
OBJECTS = objects
SOURCES = sources
INCLUDES = includes

#When you make a new folder add the name of the folder to the SUBDIRS variable
#And create the respective header file variable
#Finally and the header file variable to the HEADERS variable

## Example:
## SUBDIRS = Parsing Request Validation NewFolder
## NEWFOLDER_HEADERS = NewFolder.hpp
## HEADERS = $(PARSING_HEADERS) $(REQUEST_HEADERS) $(VALIDATION_HEADERS) $(NEWFOLDER_HEADERS)

# Subdirectories for Source and Header files
SUBDIRS =  Parsing Request Validation Response Parser Validator Http \
		   myListener Server Socket
# Header Files (without paths)
HTTP_HEADERS = HttpElement.hpp HttpRequest.hpp HttpResponse.hpp
REQUEST_HEADERS = GetRequest.hpp PostRequest.hpp RequestInformation.hpp RequestLine.hpp RequestHeaders.hpp RequestBody.hpp
RESPONSE_HEADERS = GetResponse.hpp
PARSER_HEADERS =  RequestParser.hpp ParserElement.hpp
PARSING_HEADERS = RequestLineParsing.hpp RequestHeadersParsing.hpp PostRequestBodyParsing.hpp GetRequestBodyParsing.hpp \
				  RequestBodyParsing.hpp RequestParsing.hpp


VALIDATION_HEADERS = RequestLineValidation.hpp RequestHeadersValidation.hpp PostRequestBodyValidation.hpp GetRequestBodyValidation.hpp \
					 RequestBodyValidation.hpp

VALIDATOR_HEADERS = RequestValidator.hpp
MYLISTENER_HEADERS = myListener.hpp myListenerErrors.hpp
SERVER_HEADERS = Server.hpp ServerErrors.hpp
MYSOCKET_HEADERS = mySocket.hpp mySocketErrors.hpp
# Combine Header Files
HEADERS = $(REQUEST_HEADERS) \
		  $(RESPONSE_HEADERS) \
		  $(PARSING_HEADERS) \
		  $(PARSER_HEADERS) \
		  $(VALIDATION_HEADERS) \
		  $(VALIDATOR_HEADERS) \
		  $(HTTP_HEADERS) \
		  $(MYLISTENER_HEADERS) \
		  $(SERVER_HEADERS) \
		  $(MYSOCKET_HEADERS)

# Generate Source Files by replacing .hpp with .cpp
SUBDIR_SRCS = $(patsubst %.hpp,%.cpp,$(HEADERS))

# Include main.cpp as it's not in a subdirectory
SRCS = $(SUBDIR_SRCS) main.cpp


# Use vpath to search for sources and headers in the respective subdirectories
vpath %.cpp $(addprefix $(SOURCES)/, $(SUBDIRS)) $(SOURCES)
vpath %.hpp $(addprefix $(INCLUDES)/, $(SUBDIRS))

# Generate Object File Paths
OBJ_SUBDIRS = $(patsubst %.cpp,$(OBJECTS)/%.o,$(SUBDIR_SRCS))
OBJ_MAIN = $(patsubst %.cpp,$(OBJECTS)/%.o,main.cpp)
OBJ = $(OBJ_SUBDIRS) $(OBJ_MAIN)

#Rules
all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CCXX) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJECTS)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CCXX) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_TEST)

re: fclean all

run : re
	@sleep 1
	@echo "running ! $(NAME)"
	@sleep 1
	clear
	@./$(NAME)

#DEBUG MODES GDB and Valgrind
debug: override FLAGS += -g3
debug: re
	@sleep 1
	@echo "running ! $(NAME) - GDB"
	@sleep 1
	clear
	@gdb --tui ./$(NAME)

val : re
	@sleep 1
	@echo "running ! $(NAME) - Valgrind"
	@sleep 1
	clear
	$(valgrind) ./$(NAME)

#TEST
NAME_TEST = test
SRCS_TEST = $(SUBDIR_SRCS) test.cpp
OBJ_TEST = $(patsubst %.cpp,$(OBJECTS)/%.o,test.cpp)
OBJTEST = $(OBJ_SUBDIRS) $(OBJ_TEST)

#Test rules
all_test : $(NAME_TEST)

$(NAME_TEST): $(OBJTEST) $(HEADERS)
	$(CCXX) $(FLAGS) $(OBJTEST) -o $(NAME_TEST)

fclean_test : clean
	$(RM) $(NAME_TEST)
	$(RM) $(NAME)

re_test : fclean_test all_test

tester :  re_test
	@sleep 1
	@echo "running ! $(NAME_TEST)"
	@sleep 1
	@clear
	@./$(NAME_TEST)

val_test : re_test
	@sleep 1
	@echo "running ! $(NAME_TEST) - Valgrind"
	@sleep 1
	clear
	$(valgrind) ./$(NAME_TEST)

.PHONY: all clean fclean re debug val run tester fclean_test re_test val_test all_test
