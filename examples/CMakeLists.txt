ADD_DEFINITIONS(${STATECHART_CONFIG_LINK_MACROS})

MACRO (MAKE_STATECHART_EXAMPLE subname name)
	SET (STATECHART_EXAMPLE_NAME statechart${subname}${name}example)
	ADD_EXECUTABLE (${STATECHART_EXAMPLE_NAME} ${name}.cpp)
	TARGET_LINK_LIBRARIES (${STATECHART_EXAMPLE_NAME} ${STATECHART_DEFAULT_LINK_TARGET})
ENDMACRO ()

MACRO (ADD_STATECHART_EXAMPLE name)
	MAKE_STATECHART_EXAMPLE("" ${name})
ENDMACRO ()

ADD_STATECHART_EXAMPLE(test)
ADD_STATECHART_EXAMPLE(test_complex)
