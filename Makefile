# This is a Makefile for EllipseFinder
# written by: Ali Shakeri

SHELL = /bin/sh

INSTALL = /usr/local/bin/

# "make" searches for below directories to find prerequisites
VPATH = src

CC = g++
OBJS = EllipseFinder.o fit_ellipse.o merge_images.o mouse_handler.o
LIBS = -lopencv_core -lopencv_imgproc -lopencv_objdetect -lopencv_highgui

EllipseFinder : $(OBJS)
	$(CC) -o EllipseFinder $(OBJS) $(LIBS)
	@echo 
	@echo "The compilation is complete."
	@echo


EllipseFinder.o : EllipseFinder.cpp defs.h fit_ellipse.h merge_images.h mouse_handler.h
fit_ellipse.o : fit_ellipse.cpp defs.h
merge_images.o : merge_images.cpp defs.h
mouse_handler.o: mouse_handler.cpp mouse_handler.h defs.h


# move object files to bin directory
move:
	mv $(OBJS) bin/

# clean directory
clean : 
	rm $(OBJS)

install:
	cp EllipseFinder $(INSTALL)

uninstall:
	rm "$(INSTALL)"/EllipseFinder

# create a tar file (Should be edited)
# tar :
#	tar -cvf ../version-1.0.0.tar ../3rd_step
