compiler = g++
flags = -Wall -std=c++17
compile = $(compiler) $(flags) -c
link = $(compiler) $(flags)

truefalsequestion.o : truefalsequestion.cc truefalsequestion.h 
	$(compile) $<

shortanswerquestion.o : shortanswerquestion.cc shortanswerquestion.h
	$(compile) $<

multiplechoicequestion.o : multiplechoicequestion.cc multiplechoicequestion.h
	$(compile) $<

checkit : checkit.cc
	$(link) $< -o $@

testtf : testtf.cc truefalsequestion.o checkit
	$(link) testtf.cc truefalsequestion.o -o $@
	./$@ > ./output/studenttf.txt
	./checkit 0

testsa : testsa.cc shortanswerquestion.o checkit
	$(link) testsa.cc shortanswerquestion.o -o $@
	./$@ > ./output/studentsa.txt
	./checkit 1

testmc1 : testmc1.cc multiplechoicequestion.o checkit
	$(link) testmc1.cc multiplechoicequestion.o -o $@
	./$@ > ./output/studentmc1.txt
	./checkit 2

testmc2 : testmc2.cc multiplechoicequestion.o checkit
	$(link) testmc2.cc multiplechoicequestion.o -o $@
	./$@ > ./output/studentmc2.txt
	./checkit 3

testallquestions : testallquestions.cc truefalsequestion.o shortanswerquestion.o multiplechoicequestion.o checkit
	$(link) testallquestions.cc truefalsequestion.o shortanswerquestion.o multiplechoicequestion.o -o $@
	./$@ > ./output/studentallqs.txt
	./checkit 4

clean :
	rm *.o ./output/student* testallquestions testmc2 testmc1 testsa testtf
