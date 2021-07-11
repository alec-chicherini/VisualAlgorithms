#message TARGET_ PROPERTY_. If TARGET == CMAKE message CMAKE_PROPERTY_
function(message_property TARGET_ PROPERTY_)

if(${TARGET_} STREQUAL  "CMAKE")
	set(SLASH _)
	set(MAKE_PROPERTY ${TARGET_}${SLASH}${PROPERTY_})
	set(RESULT ${${MAKE_PROPERTY}})

	string(COMPARE EQUAL "${RESULT}" "" zero_check)
	if(zero_check)
	set(RESULT "[EMPTY]")
	endif()

	message(" ### ${MAKE_PROPERTY} is " ${RESULT})
else()
	get_property(PROPERTY_VALUE
				 TARGET ${TARGET_} 
				 PROPERTY ${PROPERTY_})
	message(" ### ${PROPERTY_} in ${TARGET_} is ${PROPERTY_VALUE}")
endif()

endfunction()