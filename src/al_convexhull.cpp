// Calculates the convex hull of a given vector of points.
// Running time: O(n log n) or, if already sorted, O(n)

typedef pair<int,int> Point;
int cross(Point a, Point b) {return a.first*b.second-a.second*b.first;}
int cross(Point O, Point a, Point b) {
	return cross(Point(a.first-O.first,a.second-O.second),
		Point(b.first-O.first,b.second-O.second));
}
template<int M> void findPoints(vector<Point>& points, vector<Point>& res) {
	for (int i = 0; i < points.size(); i++) {
		Point& p = points[i];
		while (res.size()>=2 && M*cross(res.end()[-2],res.end()[-1],p)>=0)
			res.pop_back(); // > 0 instead of >= 0 keeps collinear points
		res.push_back(p);
	}
}
// USAGE: convexHull(inputPoints, outputPolygon)
void convexHull(vector<Point>& points, vector<Point>& result) {
	vector<Point> lowerResult;
	sort(points.begin(), points.end()); // remove if already sorted
	findPoints<1>(points, result);
	findPoints<-1>(points, lowerResult);
	for (int i = lowerResult.size()-2; i; i--)
		result.push_back(lowerResult[i]);
}
