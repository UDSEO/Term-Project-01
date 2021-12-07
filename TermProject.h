
class COrbitalView : public CView
{
protected: // serialization에서만 만들어집니다.

	DECLARE_DYNCREATE(COrbitalView)

public:
	COrbitalDoc* GetDocument() const;

public:
	COrbitalView();
	typedef struct population
	{
		float tx;
		float ty;
		float tz;
		float rx;
		float ry;
		float rz;
	}Population;

	int limitTX;
	int limitTY;
	int limitTZ;
	bool startGeneration = false;
	int POP_SIZE = 2000;
	int curGen = 1;
	clock_t startTime;
	float best_so_far = 9876543.0f;
	vector<Population*> myPop;

	void COrbitalView::InitEC();
	float COrbitalView::Fitness(Population* curPOP);
	void COrbitalView::myquicksort(vector<float>* tFitness, vector<Population*>* tpop, int left, int right);
	void COrbitalView::computeDistance(Population* curPOP);

	vector<vector<int>> checkVertex;
}