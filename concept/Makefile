
CPP=/usr/bin/g++-10
CPP20=/usr/bin/g++-10 -std=c++20
CPP17=/usr/bin/g++-10 -std=c++17
CPP11=/usr/bin/g++-10 -std=c++11
CPP98=/usr/bin/g++-10 -std=c++98

BINDIR=bin

all:    ${BINDIR} \
        ${BINDIR}/spaceship \
        ${BINDIR}/eq \
        ${BINDIR}/couple \
        ${BINDIR}/typedef_template \
        ${BINDIR}/print_enable_if \
        ${BINDIR}/concept_examples \
        ${BINDIR}/cond98 \
        ${BINDIR}/sub \
        ${BINDIR}/decltype \
        ${BINDIR}/true_type \
        ${BINDIR}/no_which \
        ${BINDIR}/id_type \
        ${BINDIR}/enable_if \
        ${BINDIR}/concept_no_which \
        ${BINDIR}/concept 

err: ${BINDIR}/concept_error_template_class_overload_redefine \
     ${BINDIR}/concept_error_ambiguous_class_matches_two_concepts

${BINDIR}:
	mkdir -p bin/

${BINDIR}/spaceship: spaceship.cpp
	${CPP20} $? -o $@

${BINDIR}/concept_examples: concept_examples.cpp
	${CPP20} $? -o $@

${BINDIR}/concept: concept.cpp
	${CPP20} $? -o $@

${BINDIR}/concept_no_which: concept_no_which.cpp
	${CPP20} $? -o $@

${BINDIR}/concept_error_template_class_overload_redefine: concept_error_template_class_overload_redefine.cpp
	${CPP20} $? -o $@

${BINDIR}/concept_error_ambiguous_class_matches_two_concepts: concept_error_ambiguous_class_matches_two_concepts.cpp 
	${CPP20} $? -o $@

${BINDIR}/print_enable_if: print_enable_if.cpp
	${CPP17} $? -o $@

${BINDIR}/eq: eq.cpp
	${CPP20} $? -o $@

${BINDIR}/couple: couple.cpp
	${CPP11} $? -o $@

${BINDIR}/decltype: decltype.cpp
	${CPP11} $? -o $@

${BINDIR}/true_type: true_type.cpp
	${CPP11} $? -o $@

${BINDIR}/id_type: id_type.cpp
	${CPP11} -I. $? -o $@

${BINDIR}/no_which: no_which.cpp
	${CPP11} $? -o $@

${BINDIR}/enable_if: enable_if.cpp
	${CPP11} $? -o $@

${BINDIR}/cond98: cond98.cpp
	${CPP98} $? -o $@

${BINDIR}/sub: sub.cpp
	${CPP11} $? -o $@

${BINDIR}/typedef_template: typedef_template.cpp
	${CPP98} $? -o $@

