#!/usr/bin/env seed

var flag = 0;

try
{
	assert(1 == 2);
}
catch(e)
{
	flag++;
}

try
{
	assert(0);
}
catch(e)
{
	flag++;
}

assert(flag == 2);
