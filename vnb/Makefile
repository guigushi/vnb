plat :=
CC = g++
TAGS = cpp
OBJ_DIR = obj/
DEP_DIR = dep/
LIB_DIR = ../lib/
SRCS = $(wildcard *.$(TAGS))
OBJS := $(patsubst %.$(TAGS),$(OBJ_DIR)%.o,$(notdir $(SRCS)))
DEPS := $(patsubst %.$(TAGS),$(DEP_DIR)%.d,$(notdir $(SRCS)))
TARGET = a.out

$(TARGET): $(OBJS)
	@test -d $(LIB_DIR) || mkdir -p $(LIB_DIR)
	@$(CC) -o $@ $^
-include $(DEPS)
$(OBJS):$(OBJ_DIR)%.o:%.$(TAGS)
	@test -d $(OBJ_DIR)|| mkdir -p $(OBJ_DIR)
	@test -d $(DEP_DIR)|| mkdir -p $(DEP_DIR)
	@$(CC) $(CFLAGS) -MM -MT $@ -MF $(patsubst $(OBJ_DIR)%.o, $(DEP_DIR)%.d, $@) $< > /dev/null
	@echo CC $< ...
	@$(CC) $(CFLAGS) -c $< -g -o $@
clean_obj:
	@rm -rf *.o obj/
rebuild: clean_obj all
clean:
	@rm -rf *.out *.a *.o *.so $(OBJ_DIR) $(DEP_DIR) $(LIB_DIR) *.d
debug:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(DEPS)
