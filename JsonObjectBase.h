/*
 * malloc-free JSON parser for Arduino
 * Benoit Blanchon 2014
 * MIT License
 */

#ifndef __JSONOBJECTBASE_H
#define __JSONOBJECTBASE_H

#include "utility/jsmn.h"

class JsonObjectBase
{
public:

	JsonObjectBase()
	{
		makeInvalid();
	}

	bool success() 
	{ 
		return json != 0 && tokens != 0;
	}

protected:
	
	JsonObjectBase(char* json, jsmntok_t* tokens)
	{
		this->json = json;
		this->tokens = tokens;
	}
		
	void makeInvalid()
	{
		json = 0;
		tokens = 0;
	}

	int getNestedTokenCount(int tokenIndex);

	char* json;
	jsmntok_t* tokens;
};

#endif

