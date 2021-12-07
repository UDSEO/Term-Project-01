
void COrbitalView::InitEC()
{
	startTime = clock();
	CMainFrame* pFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());

	limitTX = (int)(pFrm->m_STLManager[0]->clipingBoxMax.x * 30.0f) + 1;
	limitTY = (int)(pFrm->m_STLManager[0]->clipingBoxMax.y * 30.0f) + 1;
	limitTZ = (int)(pFrm->m_STLManager[0]->clipingBoxMax.z * 30.0f) + 1;

	srand((unsigned int)(time(NULL)));
	for (int i = 0; i < POP_SIZE; i++)
	{
		Population* newPOP = new Population();
		newPOP->tx = (float)(rand() % limitTX - limitTX / 2) / 10.0f;
		newPOP->ty = (float)(rand() % limitTY - limitTY / 2) / 10.0f;
		newPOP->tz = (float)(rand() % limitTZ - limitTZ / 2) / 10.0f;
		newPOP->rx = (float)(rand() % 3600) / 10.0f;
		newPOP->ry = (float)(rand() % 3600) / 10.0f;
		newPOP->rz = (float)(rand() % 3600) / 10.0f;

		myPop.push_back(newPOP);
	}

}

void COrbitalView::OnDraw(CDC* /*pDC*/)
{
	////////////////////////////////////////////////////////////////
	///
	///   3D model rendering
	///
	////////////////////////////////////////////////////////////////

	if (startGeneration == true)
	{
		vector<Population*> nextPop;

		for (int i = 0; i < POP_SIZE; i++)
		{
			nextPop.push_back(myPop[i]);
		}

		// cross
		srand((unsigned int)(time(NULL)));
		for (int i = 0; i < POP_SIZE / 4; i++)
		{
			Population* rpop1 = myPop[rand() % POP_SIZE];
			Population* rpop2 = myPop[rand() % POP_SIZE];

			vec4f ttvec1(rpop1->tx, rpop1->ty, rpop1->tz);
			vec4f ttvec2(rpop2->tx, rpop2->ty, rpop2->tz);

			Population* newPOP1 = new Population();
			Population* newPOP2 = new Population();

			if (1)
			{
				newPOP1->tx = rpop1->tx;	newPOP1->ty = rpop1->ty;	newPOP1->tz = rpop1->tz;
				newPOP1->rx = rpop2->rx;	newPOP1->ry = rpop2->ry;	newPOP1->rz = rpop2->rz;
				newPOP2->tx = rpop2->tx;	newPOP2->ty = rpop2->ty;	newPOP2->tz = rpop2->tz;
				newPOP2->rx = rpop1->rx;	newPOP2->ry = rpop1->ry;	newPOP2->rz = rpop1->rz;
			}
			else
			{
				if (rand() % 2 == 0)					
				{	newPOP1->tx = rpop1->tx;	newPOP2->tx = rpop2->tx; }
				else
				{	newPOP1->tx = rpop2->tx;	newPOP2->tx = rpop1->tx;}
				if (rand() % 2 == 0)
				{	newPOP1->ty = rpop1->ty;	newPOP2->ty = rpop2->ty;}
				else
				{	newPOP1->ty = rpop2->ty;	newPOP2->ty = rpop1->ty;}
				if (rand() % 2 == 0)
				{	newPOP1->tz = rpop1->tz;	newPOP2->tz = rpop2->tz;}
				else
				{	newPOP1->tz = rpop2->tz;	newPOP2->tz = rpop1->tz;}
				if (rand() % 2 == 0)					
				{	newPOP1->rx = rpop1->rx;	newPOP2->rx = rpop2->rx; }
				else
				{	newPOP1->rx = rpop2->rx;	newPOP2->rx = rpop1->rx;}
				if (rand() % 2 == 0)
				{	newPOP1->ry = rpop1->ry;	newPOP2->ry = rpop2->ry;}
				else
				{	newPOP1->ry = rpop2->ry;	newPOP2->ry = rpop1->ry;}
				if (rand() % 2 == 0)
				{	newPOP1->rz = rpop1->rz;	newPOP2->rz = rpop2->rz;}
				else
				{	newPOP1->rz = rpop2->rz;	newPOP2->rz = rpop1->rz;}
			}
			nextPop.push_back(newPOP1);
			nextPop.push_back(newPOP2);
		}

		// mutation
		int npSize = nextPop.size();
		for (int i = 0; i < npSize / 10; i++)
		{
			Population* newPOP1 = new Population();
			if (rand() % 2 == 0)
				newPOP1->tx = nextPop[i]->tx + (float)(rand() % 20 - 10) / 10.0f;
			else
				newPOP1->tx = nextPop[i]->tx;
			if (rand() % 2 == 0)
				newPOP1->ty = nextPop[i]->ty + (float)(rand() % 20 - 10) / 10.0f;
			else
				newPOP1->ty = nextPop[i]->ty;
			if (rand() % 2 == 0)
				newPOP1->tz = nextPop[i]->tz + (float)(rand() % 20 - 10) / 10.0f;
			else
				newPOP1->tz = nextPop[i]->tz;

			if (rand() % 2 == 0)
				newPOP1->rx = nextPop[i]->rx + (float)(rand() % 300 - 150) / 10.0f;
			else
				newPOP1->rx = nextPop[i]->rx;
			if (rand() % 2 == 0)
				newPOP1->ry = nextPop[i]->ry + (float)(rand() % 300 - 150) / 10.0f;
			else
				newPOP1->ry = nextPop[i]->ry;
			if (rand() % 2 == 0)
				newPOP1->rz = nextPop[i]->rz + (float)(rand() % 300 - 150) / 10.0f;
			else
				newPOP1->rz = nextPop[i]->rz;
				
			nextPop.push_back(newPOP1);
		}

		for (int i = npSize / 10; i < npSize / 10 * 2; i++)
		{
			Population* newPOP1 = new Population();
			if (rand() % 2 == 0)
				newPOP1->tx = (float)(rand() % limitTX - limitTX / 2) / 10.0f;
			else
				newPOP1->tx = nextPop[i]->tx;
			if (rand() % 2 == 0)
				newPOP1->ty = (float)(rand() % limitTX - limitTX / 2) / 10.0f;
			else
				newPOP1->ty = nextPop[i]->ty;
			if (rand() % 2 == 0)
				newPOP1->tz = (float)(rand() % limitTX - limitTX / 2) / 10.0f;
			else
				newPOP1->tz = nextPop[i]->tz;

			if (rand() % 2 == 0)
				newPOP1->rx = (float)(rand() % 3600) / 10.0f;
			else
				newPOP1->rx = nextPop[i]->rx;
			if (rand() % 2 == 0)
				newPOP1->ry = (float)(rand() % 3600) / 10.0f;
			else
				newPOP1->ry = nextPop[i]->ry;
			if (rand() % 2 == 0)
				newPOP1->rz = (float)(rand() % 3600) / 10.0f;
			else
				newPOP1->rz = nextPop[i]->rz;

			nextPop.push_back(newPOP1);
		}


		vector<float> myFitness;
		for (int i = 0; i < nextPop.size(); i++)
		{
			myFitness.push_back(Fitness(nextPop[i]));
		}
		myquicksort(&myFitness, &nextPop, 0, nextPop.size() - 1);

		myPop.clear();
			
		for (int i = 0; i < (int)(POP_SIZE / 2); i++)
			myPop.push_back(nextPop[i]);

		for (int i = 0; i < POP_SIZE - (int)(POP_SIZE / 2); i++)
		{
			Population* newPOP = new Population();
			newPOP->tx = (float)(rand() % limitTX - limitTX / 2) / 10.0f;
			newPOP->ty = (float)(rand() % limitTY - limitTY / 2) / 10.0f;
			newPOP->tz = (float)(rand() % limitTZ - limitTZ / 2) / 10.0f;
			newPOP->rx = (float)(rand() % 3600) / 10.0f;
			newPOP->ry = (float)(rand() % 3600) / 10.0f;
			newPOP->rz = (float)(rand() % 3600) / 10.0f;

			myPop.push_back(newPOP);
		}

		for (int i = (int)(POP_SIZE / 2); i < nextPop.size(); i++)
		{
			delete nextPop[i];
		}
		nextPop.clear();
		nextPop.shrink_to_fit();

		if (myFitness[0] < best_so_far)
		{
			printf("=======================================\nGenration : %d\nBest-so-far : %lf\nTime : %lf\n", curGen, myFitness[0], ((double)(clock() - startTime)) / 1000);
			best_so_far = myFitness[0];
		}
		else
		{
			printf("Generation : %d\n", curGen);
		}
		curGen++;

		if (myFitness.size() != 0)
			myFitness.clear();
			
		//startGeneration = false;
		Invalidate(TRUE);
	}
}

void COrbitalView::computeDistance(Population* curPOP)
{
	CMainFrame* pFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());

	float rx[16];
	float ry[16];
	float rz[16];
	float rResult[16];

	float result1[16];
	m_Render->matIden(rx);
	m_Render->matIden(ry);
	m_Render->matIden(rz);
	m_Render->matIden(rResult);

	float tcos = cos(curPOP->ry / 180.0f * 3.1415926535f);	float tsin = sin(curPOP->ry / 180.0f * 3.1415926535f);
	rx[5] = tcos;	rx[10] = tcos;
	rx[9] = -tsin;	rx[6] = tsin;
	tcos = cos(curPOP->rz / 180.0f * 3.1415926535f);	tsin = sin(curPOP->rz / 180.0f * 3.1415926535f);
	ry[0] = tcos;	ry[10] = tcos;
	ry[8] = tsin;	ry[2] = -tsin;
	tcos = cos(curPOP->rx / 180.0f * 3.1415926535f);	tsin = sin(curPOP->rx / 180.0f * 3.1415926535f);
	rz[0] = tcos;	rz[5] = tcos;
	rz[4] = -tsin;	rz[1] = tsin;

	m_Render->matMult(result1, ry, rx);
	m_Render->matMult(rResult, rz, result1);

	vec4f translationVec = vec4f(curPOP->tx, curPOP->ty, curPOP->tz);


	if (pFrm->m_STLManager[1]->meshDistance.size() != 0)
		pFrm->m_STLManager[1]->meshDistance.clear();

	for (int i = 0; i < pFrm->m_STLManager[1]->meshPoint.size(); i++)
	{
		vec4f tvec = pFrm->m_STLManager[1]->meshPoint[i].MultiplyMat(rResult) + translationVec;
		int vx = (tvec.x - (float)xmin) / divide;
		int vy = (tvec.y - (float)ymin) / divide;
		int vz = (tvec.z - (float)zmin) / divide;

		if (vx < 0 || vx >= ix || vy < 0 || vy >= iy || vz < 0 || vz >= iz)
		{
			pFrm->m_STLManager[1]->meshDistance.push_back(98765.0f);
			continue;
		}

		float min = 98765.0f;
		for (int j = -2; j < 2; j++)
		{
			for (int k = -2; k < 2; k++)
			{
				for (int l = -2; l < 2; l++)
				{
					if (vx + l < 0 || vx + l >= ix || vy + k < 0 || vy + k >= iy || vz + j < 0 || vz + j >= iz)
					{
						continue;
					}

					int index = (vz + j) * ix * iy + (vy + k) * ix + (vx + l);

					for (int m = 0; m < checkVertex[index].size(); m++)
					{
						float tdis = (tvec - pFrm->m_STLManager[0]->meshPoint[checkVertex[index][m]]).Length();
						if (tdis < min)
							min = tdis;
					}
				}
			}
		}

		pFrm->m_STLManager[1]->meshDistance.push_back(min);
	}
}

float COrbitalView::Fitness(Population* curPOP)
{
	CMainFrame* pFrm = dynamic_cast<CMainFrame*>(AfxGetMainWnd());
	float sum = 0.0f;

	float rx[16];
	float ry[16];
	float rz[16];
	float rResult[16];

	float result1[16];
	m_Render->matIden(rx);
	m_Render->matIden(ry);
	m_Render->matIden(rz);
	m_Render->matIden(rResult);

	float tcos = cos(curPOP->ry / 180.0f * 3.1415926535f);	float tsin = sin(curPOP->ry / 180.0f * 3.1415926535f);
	rx[5] = tcos;	rx[10] = tcos;
	rx[9] = -tsin;	rx[6] = tsin;
	tcos = cos(curPOP->rz / 180.0f * 3.1415926535f);	tsin = sin(curPOP->rz / 180.0f * 3.1415926535f);
	ry[0] = tcos;	ry[10] = tcos;
	ry[8] = tsin;	ry[2] = -tsin;
	tcos = cos(curPOP->rx / 180.0f * 3.1415926535f);	tsin = sin(curPOP->rx / 180.0f * 3.1415926535f);
	rz[0] = tcos;	rz[5] = tcos;
	rz[4] = -tsin;	rz[1] = tsin;

	m_Render->matMult(result1, ry, rx);
	m_Render->matMult(rResult, rz, result1);

	vec4f translationVec = vec4f(curPOP->tx, curPOP->ty, curPOP->tz);

	for (int i = 0; i < pFrm->m_STLManager[1]->meshPoint.size(); i++)
	{
		vec4f tvec = pFrm->m_STLManager[1]->meshPoint[i].MultiplyMat(rResult) + translationVec;
		int vx = (tvec.x - (float)xmin) / divide;
		int vy = (tvec.y - (float)ymin) / divide;
		int vz = (tvec.z - (float)zmin) / divide;

		if (vx < 0 || vx >= ix || vy < 0 || vy >= iy || vz < 0 || vz >= iz)
		{
			sum += 9876543.0f;
			continue;
		}

		float min = 9876543.0f;
		for (int j = -2; j < 2; j++)
		{
			for (int k = -2; k < 2; k++)
			{
				for (int l = -2; l < 2; l++)
				{
					if (vx + l < 0 || vx + l >= ix || vy + k < 0 || vy + k >= iy || vz + j < 0 || vz + j >= iz)
						continue;

					int index = (vz + j) * ix * iy + (vy + k) * ix + (vx + l);
					
					for (int m = 0; m < checkVertex[index].size(); m++)
					{
						float tdis = (tvec - pFrm->m_STLManager[0]->meshPoint[checkVertex[index][m]]).Length();
						if (tdis < min)
							min = tdis;
					}
				}
			}
		}
		sum += (min);
	}
	return sum / pFrm->m_STLManager[1]->meshPoint.size();
}
