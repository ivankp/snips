EXE := $(patsubst test/%.cc,test_%,$(wildcard test/*.cc))

DEP := $(EXE:test_%=.dep/%.d)

CXXFLAGS := -std=c++11 -Wall -g -Isrc

all: $(EXE)

#Don't create dependencies when cleaning
ifeq (0, $(words $(findstring $(MAKECMDGOALS), clean)))
-include $(DEP)
endif

$(EXE):
	@echo $@: $^
	g++ $(CXXFLAGS) $< -o $@

$(DEP): .dep/%.d: test/%.cc | .dep
	@g++ $(CXXFLAGS) -MM -MT '$(<:test/%.cc=test_%)' $< -MF $@

.dep:
	@mkdir $@

clean:
	@rm -rfv .dep $(EXE)
