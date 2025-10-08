
BINDIR=bin

all:	${BINDIR}/spaceship \
        ${BINDIR}/eq \
        ${BINDIR}/typedef_template \
        ${BINDIR}/print_enable_if \
        ${BINDIR}/concept_examples \
        ${BINDIR}/cond98 \
        ${BINDIR}/decltype \
        ${BINDIR}/true_type \
        ${BINDIR}/no_which \
        ${BINDIR}/id_type \
        ${BINDIR}/enable_if \
        ${BINDIR}/concept 

err:	${BINDIR}/concept_error_template_class_overload_redefine \
        ${BINDIR}/concept_error_ambiguous_class_matches_two_concepts

${BINDIR}/spaceship: spaceship.cpp
	g++-10 -std=c++20 $? -o $@

${BINDIR}/concept_examples: concept_examples.cpp
	g++-10 -std=c++20 $? -o $@

${BINDIR}/concept: concept.cpp
	g++-10 -std=c++20 $? -o $@

${BINDIR}/concept_error_template_class_overload_redefine: concept_error_template_class_overload_redefine.cpp
	g++-10 -std=c++20 $? -o $@

${BINDIR}/concept_error_ambiguous_class_matches_two_concepts: concept_error_ambiguous_class_matches_two_concepts.cpp 
	g++-10 -std=c++20 $? -o $@

${BINDIR}/print_enable_if: print_enable_if.cpp
	g++-10 -std=c++17 $? -o $@

${BINDIR}/eq: eq.cpp
	g++-10 -std=c++20 $? -o $@

${BINDIR}/decltype: decltype.cpp
	g++-10 -std=c++11 $? -o $@

${BINDIR}/true_type: true_type.cpp
	g++-10 -std=c++11 $? -o $@

${BINDIR}/id_type: id_type.cpp
	g++-10 -std=c++11 -I. $? -o $@

${BINDIR}/no_which: no_which.cpp
	g++-10 -std=c++11  $? -o $@

${BINDIR}/enable_if: enable_if.cpp
	g++-10 -std=c++11 $? -o $@

${BINDIR}/cond98: cond98.cpp
	g++-10 -std=c++98 $? -o $@

${BINDIR}/typedef_template: typedef_template.cpp
	g++-10 -std=c++98 $? -o $@

