namespace TSnap {

/////////////////////////////////////////////////
// Node centrality measures (See: http://en.wikipedia.org/wiki/Centrality)

/// Returns Degree centrality of a given node NId.
/// Degree centrality if a node is defined as its degree/(N-1), where N is the number of nodes in the network.
double GetDegreeCentr(const PUNGraph& Graph, const int& NId);
/// Returns Group Degree centrality of a given group NId.
/// Degree centrality if a node is defined as its degree/(N-1), where N is the number of nodes in the network.
//double GetGroupDegreeCentr(const PUNGraph& Graph, const PUNGraph& Group);
double GetGroupDegreeCentr(const PUNGraph& Graph, const TIntH& GroupNodes);
/// Returns Group Degree centrality of a given group NId.
/// Degree centrality if a node is defined as its degree/(N-1), where N is the number of nodes in the network.
//double GetGroupDegreeCentr(const PUNGraph& Graph, const PUNGraph& Group);
double GetGroupClosenessCentr(const PUNGraph& Graph, const TIntH& GroupNodes);
/// Returns centrality Maximum k group.
TIntH MaxCPGreedyBetter(const PUNGraph& Graph, const int k);
/// Returns centrality Maximum k group.
TIntH MaxCPGreedyBetter1(const PUNGraph& Graph, const int k);
/// Returns centrality Maximum k group.
TIntH MaxCPGreedyBetter2(const PUNGraph& Graph, const int k);
/// Returns centrality Maximum k group.
TIntH MaxCPGreedyBetter3(const PUNGraph& Graph, const int k);
/// Event importance
TIntFltH EventImportance(const PNGraph& Graph, const int k);
/// Intersect
int Intersect(TUNGraph::TNodeI Node, TIntH NNodes);
/// Intersect
int Intersect(TUNGraph::TNodeI Node, TStr NNodes);
/// Intersect
int Intersect(TUNGraph::TNodeI Node, int *NNodes, int NNodes_br);
//Load nodes list
int Intersect1(TUNGraph::TNodeI Node, TStr NNodes);
//Load nodes list
TIntH LoadNodeList(TStr InFNmNodes);
/// Returns Farness centrality of a given node NId.
/// Farness centrality of a node is the average shortest path length to all other nodes that reside is the same connected component as the given node.
/// General Routine to compute closeness centrality for both undirected and cirected graphs
template <class PGraph> double GetFarnessCentr(const PGraph& Graph, const int& NId, const bool Normalized = false);
/// Returns Closeness centrality of a given node NId.
/// Closeness centrality of a node is defined as 1/FarnessCentrality.
/// General Routine to compute closeness centrality for both undirected and cirected graphs
template <class PGraph> double GetClosenessCentr(const PGraph& Graph, const int& NId, const bool Normalized = true);
/// Returns node Eccentricity, the largest shortest-path distance from the node NId to any other node in the Graph.
/// @param IsDir false: ignore edge directions and consider edges as undirected (in case they are directed).
template <class PGraph> int GetNodeEcc(const PGraph& Graph, const int& NId, const bool& IsDir=false);

/// Computes (approximate) Node Beetweenness Centrality based on a sample of NodeFrac nodes.
/// @param NIdBtwH hash table mapping node ids to their corresponding betweenness centrality values.
/// @param NodeFrac quality of approximation. NodeFrac=1.0 gives exact betweenness values.
/// General routine to compute Betweenness Centrality for both directed and undirected graphs
template<class PGraph> void GetBetweennessCentr(const PGraph& Graph, TIntFltH& NIdBtwH, const double& NodeFrac=1.0);
/// Computes (approximate) Edge Beetweenness Centrality based on a sample of NodeFrac nodes.
/// @param EdgeBtwH hash table mapping edges (pairs of node ids) to their corresponding betweenness centrality values.
/// @param NodeFrac quality of approximation. NodeFrac=1.0 gives exact betweenness values.
/// General routine to compute Betweenness Centrality for both directed and undirected graphs
template<class PGraph> void GetBetweennessCentr(const PGraph& Graph, TIntPrFltH& EdgeBtwH, const double& NodeFrac=1.0);
/// Computes (approximate) Node and Edge Beetweenness Centrality based on a sample of NodeFrac nodes.
/// @param NIdBtwH hash table mapping node ids to their corresponding betweenness centrality values.
/// @param EdgeBtwH hash table mapping edges (pairs of node ids) to their corresponding betweenness centrality values.
/// @param NodeFrac quality of approximation. NodeFrac=1.0 gives exact betweenness values.
/// General routine to compute Betweenness Centrality for both directed and undirected graphs
template<class PGraph> void GetBetweennessCentr(const PGraph& Graph, TIntFltH& NIdBtwH, TIntPrFltH& EdgeBtwH, const double& NodeFrac=1.0);
/// Computes (approximate) Beetweenness Centrality of all nodes and all edges of the network.
/// To obtain exact betweenness values one needs to solve single-source shortest-path problem for every node.
/// To speed up the algorithm we solve the shortest-path problem for the BtwNIdV subset of nodes. This gives centrality values that are about Graph->GetNodes()/BtwNIdV.Len() times lower than the exact betweenness centrality valus.
/// See "A Faster Algorithm for Beetweenness Centrality", Ulrik Brandes, Journal of Mathematical Sociology, 2001, and
/// "Centrality Estimation in Large Networks", Urlik Brandes and Christian Pich, 2006 for more details.
/// General routine to compute Betweenness Centrality for both directed and undirected graphs
template<class PGraph> void GetBetweennessCentr(const PGraph& Graph, const TIntV& BtwNIdV, TIntFltH& NodeBtwH, const bool& DoNodeCent, TIntPrFltH& EdgeBtwH, const bool& DoEdgeCent);

/// Computes Eigenvector Centrality of all nodes in the network
/// Eigenvector Centrality of a node N is defined recursively as the average of centrality values of N's neighbors in the network.
void GetEigenVectorCentr(const PUNGraph& Graph, TIntFltH& NIdEigenH, const double& Eps=1e-4, const int& MaxIter=100);

/// PageRank
/// For more info see: http://en.wikipedia.org/wiki/PageRank
template<class PGraph> void GetPageRank(const PGraph& Graph, TIntFltH& PRankH, const double& C=0.85, const double& Eps=1e-4, const int& MaxIter=100);
#ifdef USE_OPENMP
template<class PGraph> void GetPageRankMP1(const PGraph& Graph, TIntFltH& PRankH, const double& C=0.85, const double& Eps=1e-4, const int& MaxIter=100);
template<class PGraph> void GetPageRankMP2(const PGraph& Graph, TIntFltH& PRankH, const double& C=0.85, const double& Eps=1e-4, const int& MaxIter=100);
#endif

/// Weighted PageRank (TODO: Use template)
int GetWeightedPageRank(const PNEANet Graph, TIntFltH& PRankH, const TStr& Attr, const double& C=0.85, const double& Eps=1e-4, const int& MaxIter=100);
#ifdef USE_OPENMP
int GetWeightedPageRankMP1(const PNEANet Graph, TIntFltH& PRankH, const TStr& Attr, const double& C=0.85, const double& Eps=1e-4, const int& MaxIter=100);
int GetWeightedPageRankMP2(const PNEANet Graph, TIntFltH& PRankH, const TStr& Attr, const double& C=0.85, const double& Eps=1e-4, const int& MaxIter=100);
#endif

/// HITS: Hubs and Authorities
/// For more info see: http://en.wikipedia.org/wiki/HITS_algorithm)
template<class PGraph> void GetHits(const PGraph& Graph, TIntFltH& NIdHubH, TIntFltH& NIdAuthH, const int& MaxIter=20);
#ifdef USE_OPENMP
template<class PGraph> void GetHitsMP(const PGraph& Graph, TIntFltH& NIdHubH, TIntFltH& NIdAuthH, const int& MaxIter=20);
#endif

/////////////////////////////////////////////////
// Implementation

template <class PGraph>
double GetFarnessCentr(const PGraph& Graph, const int& NId, const bool Normalized) {
  TIntH NDistH(Graph->GetNodes());
  TSnap::GetShortPath<PGraph>(Graph, NId, NDistH, true, TInt::Mx);
  double sum = 0;
  for (TIntH::TIter I = NDistH.BegI(); I < NDistH.EndI(); I++) {
    sum += I->Dat();
  }
  if (NDistH.Len() > 1) { 
    double centr = sum/double(NDistH.Len()-1); 
    if (Normalized) {
      centr *= (Graph->GetNodes() - 1)/double(NDistH.Len()-1);
    }
    return centr;
  }
  else { return 0.0; }
}

template <class PGraph>
double GetClosenessCentr(const PGraph& Graph, const int& NId, const bool Normalized) {
  const double Farness = GetFarnessCentr<PGraph> (Graph, NId, Normalized);
  if (Farness != 0.0) { return 1.0/Farness; }
  else { return 0.0; }
}

template <class PGraph>
int GetNodeEcc(const PGraph& Graph, const int& NId, const bool& IsDir) {
  int NodeEcc;
  int Dist;
  TBreathFS<PGraph> BFS(Graph);
  // get shortest paths to all the nodes
  BFS.DoBfs(NId, true, ! IsDir, -1, TInt::Mx);

  NodeEcc = 0;
  // find the largest value
  for (int i = 0; i < BFS.NIdDistH.Len(); i++) {
    Dist = BFS.NIdDistH[i];
    if (Dist > NodeEcc) {
      NodeEcc = Dist;
    }
  }
  return NodeEcc;
}

// Page Rank -- there are two different implementations (uncomment the desired 2 lines):
//   Berkhin -- (the correct way) see Algorithm 1 of P. Berkhin, A Survey on PageRank Computing, Internet Mathematics, 2005
//   iGraph -- iGraph implementation(which treats leaked PageRank in a funny way)
// This implementation is an unoptimized version, it accesses nodes via a hash table.
template<class PGraph>
void GetPageRank_v1(const PGraph& Graph, TIntFltH& PRankH, const double& C, const double& Eps, const int& MaxIter) {
  const int NNodes = Graph->GetNodes();
  //const double OneOver = 1.0/double(NNodes);
  PRankH.Gen(NNodes);
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    PRankH.AddDat(NI.GetId(), 1.0/NNodes);
    //IAssert(NI.GetId() == PRankH.GetKey(PRankH.Len()-1));
  }
  TFltV TmpV(NNodes);
  for (int iter = 0; iter < MaxIter; iter++) {
    int j = 0;
    for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++, j++) {
      TmpV[j] = 0;
      for (int e = 0; e < NI.GetInDeg(); e++) {
        const int InNId = NI.GetInNId(e);
        const int OutDeg = Graph->GetNI(InNId).GetOutDeg();
        if (OutDeg > 0) {
          TmpV[j] += PRankH.GetDat(InNId) / OutDeg; }
      }
      TmpV[j] =  C*TmpV[j]; // Berkhin (the correct way of doing it)
      //TmpV[j] =  C*TmpV[j] + (1.0-C)*OneOver; // iGraph
    }
    double diff=0, sum=0, NewVal;
    for (int i = 0; i < TmpV.Len(); i++) { sum += TmpV[i]; }
    const double Leaked = (1.0-sum) / double(NNodes);
    for (int i = 0; i < PRankH.Len(); i++) { // re-instert leaked PageRank
      NewVal = TmpV[i] + Leaked; // Berkhin
      //NewVal = TmpV[i] / sum;  // iGraph
      diff += fabs(NewVal-PRankH[i]);
      PRankH[i] = NewVal;
    }
    if (diff < Eps) { break; }
  }
}

// Page Rank -- there are two different implementations (uncomment the desired 2 lines):
//   Berkhin -- (the correct way) see Algorithm 1 of P. Berkhin, A Survey on PageRank Computing, Internet Mathematics, 2005
//   iGraph -- iGraph implementation(which treats leaked PageRank in a funny way)
// This implementation is an optimized version, it builds a vector and accesses nodes via the vector.
template<class PGraph>
void GetPageRank(const PGraph& Graph, TIntFltH& PRankH, const double& C, const double& Eps, const int& MaxIter) {
  const int NNodes = Graph->GetNodes();
  TVec<typename PGraph::TObj::TNodeI> NV;
  PRankH.Gen(NNodes);
  int MxId = -1;
  //time_t t = time(0);
  //printf("%s", ctime(&t));
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    NV.Add(NI);
    PRankH.AddDat(NI.GetId(), 1.0/NNodes);
    int Id = NI.GetId();
    if (Id > MxId) {
      MxId = Id;
    }
  }
  //t = time(0);
  //printf("%s", ctime(&t));

  TFltV PRankV(MxId+1);
  TIntV OutDegV(MxId+1);

  //#pragma omp parallel for schedule(dynamic,10000)
  for (int j = 0; j < NNodes; j++) {
    typename PGraph::TObj::TNodeI NI = NV[j];
    int Id = NI.GetId();
    PRankV[Id] = 1.0/NNodes;
    OutDegV[Id] = NI.GetOutDeg();
  }

  TFltV TmpV(NNodes);

  for (int iter = 0; iter < MaxIter; iter++) {
    //time_t t = time(0);
    //printf("%s%d\n", ctime(&t),iter);
    //#pragma omp parallel for schedule(dynamic,10000)
    for (int j = 0; j < NNodes; j++) {
      typename PGraph::TObj::TNodeI NI = NV[j];
      TFlt Tmp = 0;
      for (int e = 0; e < NI.GetInDeg(); e++) {
        const int InNId = NI.GetInNId(e);
        const int OutDeg = OutDegV[InNId];
        //if (OutDeg != OutDegV[InNId]) {
          //printf("*** ERROR *** InNId %d, OutDeg %d, OutDegV %d\n",
            //InNId, OutDeg, OutDegV[InNId].Val);
        //}
        if (OutDeg > 0) {
          Tmp += PRankV[InNId] / OutDeg;
        }
      }
      TmpV[j] =  C*Tmp; // Berkhin (the correct way of doing it)
    }
    double sum = 0;
    //#pragma omp parallel for reduction(+:sum) schedule(dynamic,10000)
    for (int i = 0; i < TmpV.Len(); i++) { sum += TmpV[i]; }
    const double Leaked = (1.0-sum) / double(NNodes);

    double diff = 0;
    //#pragma omp parallel for reduction(+:diff) schedule(dynamic,10000)
    for (int i = 0; i < NNodes; i++) {
      typename PGraph::TObj::TNodeI NI = NV[i];
      double NewVal = TmpV[i] + Leaked; // Berkhin
      int Id = NI.GetId();
      diff += fabs(NewVal-PRankV[Id]);
      PRankV[Id] = NewVal;
    }
    //printf("counts %d %d\n", hcount1, hcount2);
    if (diff < Eps) { break; }
  }

  //#pragma omp parallel for schedule(dynamic,10000)
  for (int i = 0; i < NNodes; i++) {
    typename PGraph::TObj::TNodeI NI = NV[i];
    PRankH[i] = PRankV[NI.GetId()];
  }
}

#ifdef USE_OPENMP
// Page Rank -- there are two different implementations (uncomment the desired 2 lines):
//   Berkhin -- (the correct way) see Algorithm 1 of P. Berkhin, A Survey on PageRank Computing, Internet Mathematics, 2005
//   iGraph -- iGraph implementation(which treats leaked PageRank in a funny way)
// This is a parallel, non-optimized version.
template<class PGraph>
void GetPageRankMP1(const PGraph& Graph, TIntFltH& PRankH, const double& C, const double& Eps, const int& MaxIter) {
  const int NNodes = Graph->GetNodes();
  TVec<typename PGraph::TObj::TNodeI> NV;
  //const double OneOver = 1.0/double(NNodes);
  PRankH.Gen(NNodes);
  //time_t t = time(0);
  //printf("%s", ctime(&t));
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    NV.Add(NI);
    PRankH.AddDat(NI.GetId(), 1.0/NNodes);
    //IAssert(NI.GetId() == PRankH.GetKey(PRankH.Len()-1));
  }

  TFltV TmpV(NNodes);

  //int hcount1 = 0;
  //int hcount2 = 0;
  for (int iter = 0; iter < MaxIter; iter++) {
    //time_t t = time(0);
    //printf("%s%d\n", ctime(&t),iter);
    //int j = 0;
    //for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++, j++) {
    #pragma omp parallel for schedule(dynamic,10000)
    for (int j = 0; j < NNodes; j++) {
      typename PGraph::TObj::TNodeI NI = NV[j];
      TmpV[j] = 0;
      for (int e = 0; e < NI.GetInDeg(); e++) {
        const int InNId = NI.GetInNId(e);
        //hcount1++;
        const int OutDeg = Graph->GetNI(InNId).GetOutDeg();
        if (OutDeg > 0) {
          //hcount2++;
          TmpV[j] += PRankH.GetDat(InNId) / OutDeg;
        }
      }
      TmpV[j] =  C*TmpV[j]; // Berkhin (the correct way of doing it)
      //TmpV[j] =  C*TmpV[j] + (1.0-C)*OneOver; // iGraph
    }
    double sum = 0;
    #pragma omp parallel for reduction(+:sum) schedule(dynamic,10000)
    for (int i = 0; i < TmpV.Len(); i++) { sum += TmpV[i]; }
    const double Leaked = (1.0-sum) / double(NNodes);

    double diff = 0;
    #pragma omp parallel for reduction(+:diff) schedule(dynamic,10000)
    for (int i = 0; i < PRankH.Len(); i++) { // re-instert leaked PageRank
      double NewVal = TmpV[i] + Leaked; // Berkhin
      //NewVal = TmpV[i] / sum;  // iGraph
      diff += fabs(NewVal-PRankH[i]);
      PRankH[i] = NewVal;
    }
    //printf("counts %d %d\n", hcount1, hcount2);
    if (diff < Eps) { break; }
  }
}

// Page Rank -- there are two different implementations (uncomment the desired 2 lines):
//   Berkhin -- (the correct way) see Algorithm 1 of P. Berkhin, A Survey on PageRank Computing, Internet Mathematics, 2005
//   iGraph -- iGraph implementation(which treats leaked PageRank in a funny way)
// This is a parallel, optimized version.
template<class PGraph>
void GetPageRankMP2(const PGraph& Graph, TIntFltH& PRankH, const double& C, const double& Eps, const int& MaxIter) {
  const int NNodes = Graph->GetNodes();
  //TIntV NV;
  TVec<typename PGraph::TObj::TNodeI> NV;
  //const double OneOver = 1.0/double(NNodes);
  PRankH.Gen(NNodes);

  //double t1 = omp_get_wtime();
  int MxId = -1;
  //time_t t = time(0);
  //printf("%s", ctime(&t));
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    NV.Add(NI);
    PRankH.AddDat(NI.GetId(), 1.0/NNodes);
    int Id = NI.GetId();
    if (Id > MxId) {
      MxId = Id;
    }
    //IAssert(NI.GetId() == PRankH.GetKey(PRankH.Len()-1));
  }
  //t = time(0);
  //printf("%s", ctime(&t));
  //double t2 = omp_get_wtime();
  //printf("Pre-process %f\n", t2-t1);

  TFltV PRankV(MxId+1);
  TIntV OutDegV(MxId+1);
  //printf("MxId %d\n", MxId);

  //for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
  #pragma omp parallel for schedule(dynamic,10000)
  for (int j = 0; j < NNodes; j++) {
    typename PGraph::TObj::TNodeI NI = NV[j];
    int Id = NI.GetId();
    PRankV[Id] = 1.0/NNodes;
    OutDegV[Id] = NI.GetOutDeg();
  }
  //double t3 = omp_get_wtime();
  //printf("Collect degrees %f\n", t3-t2);

  TFltV TmpV(NNodes);
  //int hcount1 = 0;
  //int hcount2 = 0;
  //double i1 = 0;
  //double i2 = 0;
  //double i3 = 0;
  for (int iter = 0; iter < MaxIter; iter++) {
    //time_t t = time(0);
    //printf("%s%d\n", ctime(&t),iter);
    //int j = 0;
    //for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++, j++) {
    //double ti1 = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic,10000)
    for (int j = 0; j < NNodes; j++) {
      //typename PGraph::TObj::TNodeI NI = Graph->GetNI(NV[j]);
      typename PGraph::TObj::TNodeI NI = NV[j];
      TFlt Tmp = 0;
      //TmpV[j] = 0;
      for (int e = 0; e < NI.GetInDeg(); e++) {
        const int InNId = NI.GetInNId(e);
        //hcount1++;
        //const int OutDeg = Graph->GetNI(InNId).GetOutDeg();
        const int OutDeg = OutDegV[InNId];
        if (OutDeg > 0) {
          //hcount2++;
          //TmpV[j] += PRankH.GetDat(InNId) / OutDeg;
          //TmpV[j] += PRankV[InNId] / OutDeg;
          Tmp += PRankV[InNId] / OutDeg;
        }
      }
      TmpV[j] =  C*Tmp; // Berkhin (the correct way of doing it)
      //TmpV[j] =  C*TmpV[j]; // Berkhin (the correct way of doing it)
      ////TmpV[j] =  C*TmpV[j] + (1.0-C)*OneOver; // iGraph
    }
    //double ti2 = omp_get_wtime();
    //i1 += (ti2 - ti1);

    double sum = 0;
    #pragma omp parallel for reduction(+:sum) schedule(dynamic,10000)
    for (int i = 0; i < TmpV.Len(); i++) { sum += TmpV[i]; }
    const double Leaked = (1.0-sum) / double(NNodes);
    //double ti3 = omp_get_wtime();
    //i2 += (ti3 - ti2);

    double diff = 0;
    #pragma omp parallel for reduction(+:diff) schedule(dynamic,10000)
    for (int i = 0; i < NNodes; i++) {
      double NewVal = TmpV[i] + Leaked; // Berkhin
      //NewVal = TmpV[i] / sum;  // iGraph
      int Id = NV[i].GetId();
      diff += fabs(NewVal-PRankV[Id]);
      PRankV[Id] = NewVal;
    }
    //double ti4 = omp_get_wtime();
    //i3 += (ti4 - ti3);
    //printf("counts %d %d\n", hcount1, hcount2);
    if (diff < Eps) { break; }
  }
  //double t4 = omp_get_wtime();
  //printf("Iterate %f\n", t4-t3);
  //printf("Compute new weights %f\n", i1);
  //printf("Compute sum %f\n", i2);
  //printf("Update weights %f\n", i3);

  #pragma omp parallel for schedule(dynamic,10000)
  for (int i = 0; i < NNodes; i++) {
    typename PGraph::TObj::TNodeI NI = NV[i];
    //PRankH.AddDat(NI.GetId(), PRankV[NI.GetId()]);
    PRankH[i] = PRankV[NI.GetId()];
  }
  //double t5 = omp_get_wtime();
  //printf("Post-process %f\n", t5-t4);
}

template<class PGraph>
void GetPageRankMP3(const PGraph& Graph, TIntFltH& PRankH, const double& C, const double& Eps, const int& MaxIter) {
  const int NNodes = Graph->GetNodes();
  TVec<typename PGraph::TObj::TNodeI> NV;
  PRankH.Gen(NNodes);
  TIntIntH NIdH(NNodes);
  //double t1 = omp_get_wtime();
  int c = 0;
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    NV.Add(NI);
    PRankH.AddDat(NI.GetId(), 1.0/NNodes);
    int Id = NI.GetId();
    NIdH.AddDat(Id, c++);
  }
  //double t2 = omp_get_wtime();
  //printf("Preprocessing %f\n", t2-t1);

  TFltV PRankV(NNodes);
  TIntV OutDegV(NNodes);
  #pragma omp parallel for schedule(dynamic,10000)
  for (int j = 0; j < NNodes; j++) {
    int Id = NV[j].GetId();
    PRankV[NIdH.GetDat(Id)] = 1.0/NNodes;
    OutDegV[NIdH.GetDat(Id)] = NV[j].GetOutDeg();
  }
  //double t3 = omp_get_wtime();
  //printf("Collect degree %f\n", t3-t2);

  TFltV TmpV(NNodes);

  for (int iter = 0; iter < MaxIter; iter++) {
    #pragma omp parallel for schedule(dynamic,10000)
    for (int j = 0; j < NNodes; j++) {
      typename PGraph::TObj::TNodeI NI = NV[j];
      TFlt Tmp = 0;
      for (int e = 0; e < NI.GetInDeg(); e++) {
        const int InNId = NIdH.GetDat(NI.GetInNId(e));
        const int OutDeg = OutDegV[InNId];
        if (OutDeg > 0) {
          Tmp += PRankV[InNId] / OutDeg;
        }
      }
      TmpV[j] =  C*Tmp; // Berkhin (the correct way of doing it)
      ////TmpV[j] =  C*TmpV[j] + (1.0-C)*OneOver; // iGraph
    }
    double sum = 0;
    #pragma omp parallel for reduction(+:sum) schedule(dynamic,10000)
    for (int i = 0; i < TmpV.Len(); i++) { sum += TmpV[i]; }
    const double Leaked = (1.0-sum) / double(NNodes);

    double diff = 0;
    #pragma omp parallel for reduction(+:diff) schedule(dynamic,10000)
    for (int i = 0; i < NNodes; i++) {
      typename PGraph::TObj::TNodeI NI = NV[i];
      double NewVal = TmpV[i] + Leaked; // Berkhin
      //NewVal = TmpV[i] / sum;  // iGraph
      int Id = NIdH.GetDat(NI.GetId());
      diff += fabs(NewVal-PRankV[Id]);
      PRankV[Id] = NewVal;
    }
    if (diff < Eps) { break; }
  }
  //double t4 = omp_get_wtime();
  //printf("Iterate %f\n", t4-t3);

  #pragma omp parallel for schedule(dynamic,10000)
  for (int i = 0; i < NNodes; i++) {
    typename PGraph::TObj::TNodeI NI = NV[i];
    PRankH[i] = PRankV[NIdH.GetDat(NI.GetId())];
  }
  //double t5 = omp_get_wtime();
  //printf("Post-process %f\n", t5-t4);
}

template<class PGraph>
void GetPageRankMNetMP(const PGraph& Graph, TIntFltH& PRankH, const double& C, const double& Eps, const int& MaxIter) {
  const int NNodes = Graph->GetNodes();
  TVec<typename PGraph::TObj::TNodeI> NV;
  PRankH.Gen(NNodes);

  //double t1 = omp_get_wtime();
  int MxNTypeId = Graph->GetMxNTypeId();
  TVec<TFltV> PRankVV(MxNTypeId);
  TVec<TIntV> OutDegVV(MxNTypeId);

  for (int NTypeId = 0; NTypeId < MxNTypeId; NTypeId++) {
    int MxNId = Graph->GetMxNId(NTypeId);
    PRankVV[NTypeId] = TFltV(MxNId);
    OutDegVV[NTypeId] = TIntV(MxNId);
  }
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    NV.Add(NI);
    PRankH.AddKey(NI.GetId()); // Put a placeholder
  }
  #pragma omp parallel for schedule(dynamic,10000)
  for (int j = 0; j < NNodes; j++) {
    typename PGraph::TObj::TNodeI NI = NV[j];
    int Id = NI.GetId();
    int NTypeId = Graph->GetNTypeId(Id);
    int LocalNId = Graph->GetLocalNId(Id);
    PRankVV[NTypeId][LocalNId] = 1.0/NNodes;
    OutDegVV[NTypeId][LocalNId] = NI.GetOutDeg();
  }
  //double t2 = omp_get_wtime();
  //printf("Pre-process %f\n", t2-t1);

  TFltV TmpV(NNodes);
  //double i1 = 0;
  //double i2 = 0;
  //double i3 = 0;
  for (int iter = 0; iter < MaxIter; iter++) {
    //double ti1 = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic,10000)
    for (int j = 0; j < NNodes; j++) {
      typename PGraph::TObj::TNodeI NI = NV[j];
      TFlt Tmp = 0;
      for (int e = 0; e < NI.GetInDeg(); e++) {
        const int InNId = NI.GetInNId(e);
        const int InNTypeId = Graph->GetNTypeId(InNId);
        const int InLocalNId = Graph->GetLocalNId(InNId);
        const int OutDeg = OutDegVV[InNTypeId][InLocalNId];
        Tmp += (OutDeg > 0) ? (PRankVV[InNTypeId][InLocalNId] / OutDeg) : 0;
      }
      TmpV[j] =  C*Tmp; // Berkhin (the correct way of doing it)
    }
    //double ti2 = omp_get_wtime();
    //i1 += (ti2 - ti1);

    double sum = 0;
    #pragma omp parallel for reduction(+:sum) schedule(dynamic,10000)
    for (int i = 0; i < TmpV.Len(); i++) { sum += TmpV[i]; }
    const double Leaked = (1.0-sum) / double(NNodes);
    //double ti3 = omp_get_wtime();
    //i2 += (ti3 - ti2);

    double diff = 0;
    #pragma omp parallel for reduction(+:diff) schedule(dynamic,10000)
    for (int i = 0; i < NNodes; i++) {
      double NewVal = TmpV[i] + Leaked; // Berkhin
      //NewVal = TmpV[i] / sum;  // iGraph
      int Id = NV[i].GetId();
      int NTypeId = Graph->GetNTypeId(Id);
      int LocalNId = Graph->GetLocalNId(Id);
      diff += fabs(NewVal-PRankVV[NTypeId][LocalNId]);
      PRankVV[NTypeId][LocalNId] = NewVal;
    }
    //double ti4 = omp_get_wtime();
    //i3 += (ti4 - ti3);
    //printf("counts %d %d\n", hcount1, hcount2);
    if (diff < Eps) { break; }
  }
  //double t3 = omp_get_wtime();
  //printf("Iterate %f\n", t3-t2);
  //printf("Compute new weights %f\n", i1);
  //printf("Compute sum %f\n", i2);
  //printf("Update weights %f\n", i3);

  #pragma omp parallel for schedule(dynamic,10000)
  for (int i = 0; i < NNodes; i++) {
    typename PGraph::TObj::TNodeI NI = NV[i];
    int NTypeId = NI.GetTypeId();
    int LocalNId = NI.GetLocalId();
    PRankH[i] = PRankVV[NTypeId][LocalNId];
  }
  //double t4 = omp_get_wtime();
  //printf("Post-process %f\n", t4-t3);
}
#endif // USE_OPENMP

/// Betweenness Centrality
template<class PGraph>
void GetBetweennessCentr(const PGraph& Graph, const TIntV& BtwNIdV, TIntFltH& NodeBtwH, const bool& DoNodeCent, TIntPrFltH& EdgeBtwH, const bool& DoEdgeCent) {
  if (DoNodeCent) { NodeBtwH.Clr(); }
  if (DoEdgeCent) { EdgeBtwH.Clr(); }
  const int nodes = Graph->GetNodes();
  TIntS S(nodes);
  TIntQ Q(nodes);
  TIntIntVH P(nodes); // one vector for every node
  TIntFltH delta(nodes);
  TIntH sigma(nodes), d(nodes);
  // init
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    if (DoNodeCent) {
      NodeBtwH.AddDat(NI.GetId(), 0); }
    if (DoEdgeCent) {
      for (int e = 0; e < NI.GetOutDeg(); e++) {
        if (NI.GetId() < NI.GetOutNId(e)) {
          EdgeBtwH.AddDat(TIntPr(NI.GetId(), NI.GetOutNId(e)), 0); }
      }
    }
    sigma.AddDat(NI.GetId(), 0);
    d.AddDat(NI.GetId(), -1);
    P.AddDat(NI.GetId(), TIntV());
    delta.AddDat(NI.GetId(), 0);
  }
  // calc betweeness
  for (int k=0; k < BtwNIdV.Len(); k++) {
    const typename PGraph::TObj::TNodeI NI = Graph->GetNI(BtwNIdV[k]);
    // reset
    for (int i = 0; i < sigma.Len(); i++) {
      sigma[i]=0;  d[i]=-1;  delta[i]=0;  P[i].Clr(false);
    }
    S.Clr(false);
    Q.Clr(false);
    sigma.AddDat(NI.GetId(), 1);
    d.AddDat(NI.GetId(), 0);
    Q.Push(NI.GetId());
    while (! Q.Empty()) {
      const int v = Q.Top();  Q.Pop();
      const typename PGraph::TObj::TNodeI NI2 = Graph->GetNI(v);
      S.Push(v);
      const int VDat = d.GetDat(v);
      for (int e = 0; e < NI2.GetOutDeg(); e++) {
        const int w = NI2.GetOutNId(e);
        if (d.GetDat(w) < 0) { // find w for the first time
          Q.Push(w);
          d.AddDat(w, VDat+1);
        }
        //shortest path to w via v ?
        if (d.GetDat(w) == VDat+1) {
          sigma.AddDat(w) += sigma.GetDat(v);
          P.GetDat(w).Add(v);
        }
      }
    }
    while (! S.Empty()) {
      const int w = S.Top();
      const double SigmaW = sigma.GetDat(w);
      const double DeltaW = delta.GetDat(w);
      const TIntV NIdV = P.GetDat(w);
      S.Pop();
      for (int i = 0; i < NIdV.Len(); i++) {
        const int nid = NIdV[i];
        const double c = (sigma.GetDat(nid)*1.0/SigmaW) * (1+DeltaW);
        delta.AddDat(nid) += c;
        if (DoEdgeCent) {
          EdgeBtwH.AddDat(TIntPr(TMath::Mn(nid, w), TMath::Mx(nid, w))) += c; }
      }
      if (DoNodeCent && w != NI.GetId()) {
        NodeBtwH.AddDat(w) += delta.GetDat(w)/2.0; }
    }
  }
}

template<class PGraph>
void GetBetweennessCentr(const PGraph& Graph, TIntFltH& NodeBtwH, const double& NodeFrac) {
  TIntPrFltH EdgeBtwH;
  TIntV NIdV;  Graph->GetNIdV(NIdV);
  if (NodeFrac < 1.0) { // calculate beetweenness centrality for a subset of nodes
    NIdV.Shuffle(TInt::Rnd);
    for (int i = int((1.0-NodeFrac)*NIdV.Len()); i > 0; i--) {
      NIdV.DelLast(); }
  }
  GetBetweennessCentr<PGraph> (Graph, NIdV, NodeBtwH, true, EdgeBtwH, false);
}

template<class PGraph>
void GetBetweennessCentr(const PGraph& Graph, TIntPrFltH& EdgeBtwH, const double& NodeFrac) {
  TIntFltH NodeBtwH;
  TIntV NIdV;  Graph->GetNIdV(NIdV);
  if (NodeFrac < 1.0) { // calculate beetweenness centrality for a subset of nodes
    NIdV.Shuffle(TInt::Rnd);
    for (int i = int((1.0-NodeFrac)*NIdV.Len()); i > 0; i--) {
      NIdV.DelLast(); }
  }
  GetBetweennessCentr<PGraph> (Graph, NIdV, NodeBtwH, false, EdgeBtwH, true);
}

template<class PGraph>
void GetBetweennessCentr(const PGraph& Graph, TIntFltH& NodeBtwH, TIntPrFltH& EdgeBtwH, const double& NodeFrac) {
  TIntV NIdV;  Graph->GetNIdV(NIdV);
  if (NodeFrac < 1.0) { // calculate beetweenness centrality for a subset of nodes
    NIdV.Shuffle(TInt::Rnd);
    for (int i = int((1.0-NodeFrac)*NIdV.Len()); i > 0; i--) {
      NIdV.DelLast(); }
  }
  GetBetweennessCentr<PGraph> (Graph, NIdV, NodeBtwH, true, EdgeBtwH, true);
}

template<class PGraph>
void GetHits(const PGraph& Graph, TIntFltH& NIdHubH, TIntFltH& NIdAuthH, const int& MaxIter) {
  const int NNodes = Graph->GetNodes();
  NIdHubH.Gen(NNodes);
  NIdAuthH.Gen(NNodes);
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    NIdHubH.AddDat(NI.GetId(), 1.0);
    NIdAuthH.AddDat(NI.GetId(), 1.0);
  }
  double Norm=0;
  for (int iter = 0; iter < MaxIter; iter++) {
    // update authority scores
    Norm = 0;
    for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
      double& Auth = NIdAuthH.GetDat(NI.GetId()).Val;
      Auth = 0;
      for (int e = 0; e < NI.GetInDeg(); e++) {
        Auth +=  NIdHubH.GetDat(NI.GetInNId(e)); }
      Norm += Auth*Auth;
    }
    Norm = sqrt(Norm);
    for (int i = 0; i < NIdAuthH.Len(); i++) { NIdAuthH[i] /= Norm; }
    // update hub scores
    for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
      double& Hub = NIdHubH.GetDat(NI.GetId()).Val;
      Hub = 0;
      for (int e = 0; e < NI.GetOutDeg(); e++) {
        Hub += NIdAuthH.GetDat(NI.GetOutNId(e)); }
      Norm += Hub*Hub;
    }
    Norm = sqrt(Norm);
    for (int i = 0; i < NIdHubH.Len(); i++) { NIdHubH[i] /= Norm; }
  }
  // make sure Hub and Authority scores normalize to L2 norm 1
  Norm = 0.0;
  for (int i = 0; i < NIdHubH.Len(); i++) { Norm += TMath::Sqr(NIdHubH[i]); }
  Norm = sqrt(Norm);
  for (int i = 0; i < NIdHubH.Len(); i++) { NIdHubH[i] /= Norm; }
  Norm = 0.0;
  for (int i = 0; i < NIdAuthH.Len(); i++) { Norm += TMath::Sqr(NIdAuthH[i]); }
  Norm = sqrt(Norm);
  for (int i = 0; i < NIdAuthH.Len(); i++) { NIdAuthH[i] /= Norm; }
}

#ifdef USE_OPENMP
template<class PGraph>
void GetHitsMP(const PGraph& Graph, TIntFltH& NIdHubH, TIntFltH& NIdAuthH, const int& MaxIter) {
  const int NNodes = Graph->GetNodes();
  TIntV NV;
  NIdHubH.Gen(NNodes);
  NIdAuthH.Gen(NNodes);
  for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    NV.Add(NI.GetId());
    NIdHubH.AddDat(NI.GetId(), 1.0);
    NIdAuthH.AddDat(NI.GetId(), 1.0);
  }
  double Norm=0;
  for (int iter = 0; iter < MaxIter; iter++) {
    // update authority scores
    Norm = 0;
    //for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    #pragma omp parallel for reduction(+:Norm) schedule(dynamic,1000)
    for (int i = 0; i < NNodes; i++) {
      typename PGraph::TObj::TNodeI NI = Graph->GetNI(NV[i]);
      double& Auth = NIdAuthH.GetDat(NI.GetId()).Val;
      Auth = 0;
      for (int e = 0; e < NI.GetInDeg(); e++) {
        Auth +=  NIdHubH.GetDat(NI.GetInNId(e)); }
      Norm = Norm + Auth*Auth;
    }
    Norm = sqrt(Norm);
    for (int i = 0; i < NIdAuthH.Len(); i++) { NIdAuthH[i] /= Norm; }
    // update hub scores
    //for (typename PGraph::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
    #pragma omp parallel for reduction(+:Norm) schedule(dynamic,1000)
    for (int i = 0; i < NNodes; i++) {
      typename PGraph::TObj::TNodeI NI = Graph->GetNI(NV[i]);
      double& Hub = NIdHubH.GetDat(NI.GetId()).Val;
      Hub = 0;
      for (int e = 0; e < NI.GetOutDeg(); e++) {
        Hub += NIdAuthH.GetDat(NI.GetOutNId(e)); }
      Norm = Norm + Hub*Hub;
    }
    Norm = sqrt(Norm);
    for (int i = 0; i < NIdHubH.Len(); i++) { NIdHubH[i] /= Norm; }
  }
  // make sure Hub and Authority scores normalize to L2 norm 1
  Norm = 0.0;
  for (int i = 0; i < NIdHubH.Len(); i++) { Norm += TMath::Sqr(NIdHubH[i]); }
  Norm = sqrt(Norm);
  for (int i = 0; i < NIdHubH.Len(); i++) { NIdHubH[i] /= Norm; }
  Norm = 0.0;
  for (int i = 0; i < NIdAuthH.Len(); i++) { Norm += TMath::Sqr(NIdAuthH[i]); }
  Norm = sqrt(Norm);
  for (int i = 0; i < NIdAuthH.Len(); i++) { NIdAuthH[i] /= Norm; }
}
#endif

}; // namespace TSnap
