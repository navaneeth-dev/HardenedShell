#include <windows.h>

#include "sandbox.h"
#include "target.h"

int main()
{
	if (IsSandbox())
		return 0;

	if (!IsTarget())
		return 0;

	return 0;
}
