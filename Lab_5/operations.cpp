#include "entitate.h"
#include "repository.h"
#include "operations.h"

void all_in_first_quadrant(Repository& repo, Entitate* v, int& len)
{
	len = 0;
	for (int i = 0; i < repo.getNrEntitati(); i++)
	{
		Entitate e(repo.elemAt(i));
		if (e.getParteReala() > 0 && e.getParteImaginara() > 0) v[len++] = e;
	}
}

void max_secv_entitati_egale(Repository& repo, int& start, int& end)
{
	int maxim, len;
	maxim = len = 1;
	start = end = 0;
	for (int i = 0; i < repo.getNrEntitati() - 1; i++)
		if (repo.elemAt(i) == repo.elemAt(i + 1)) len++;
		else
		{
			if (len > maxim) { maxim = len; end = i; }
			len = 1;
		}
	if (len > maxim) { maxim = len; end = repo.getNrEntitati() - 1; }
	start = end - maxim + 1;
}
