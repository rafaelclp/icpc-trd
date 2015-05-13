// Calculates the convex hull of a given vector of points.
// Running time: O(n log n) or, if already sorted, O(n)

typedef pair<int,int> Point;
inline int cross(Point a, Point b) { return a.first*b.second - a.second*b.first; }
inline int cross(Point O, Point a, Point b) {
	return cross(Point(a.first-O.first,a.second-O.second), Point(b.first-O.first,b.second-O.second));
}
template<int M> void findPoints(vector<Point>& points, vector<Point>& result) {
	for (int i = 0; i < points.size(); i++) {
		Point& p = points[i];
		while (result.size() >= 2 && M*cross(result.end()[-2], result.end()[-1], p) >= 0)
			result.pop_back(); // > 0 instead of >= 0 keeps collinear points
		result.push_back(p);
	}
}
// USAGE: convexHull(inputPoints, outputPolygon)
void convexHull(vector<Point>& points, vector<Point>& result) {
	vector<Point> lowerResult;
	sort(points.begin(), points.end()); // remove if already sorted by <x,y>
	findPoints<1>(points, result);
	findPoints<-1>(points, lowerResult);
	for (int i = lowerResult.size()-2; i; i--)
		result.push_back(lowerResult[i]);
}
