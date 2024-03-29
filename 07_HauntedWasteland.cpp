// https://adventofcode.com/2023/day/8


/* 

--- Day 8: Haunted Wasteland ---

You're still riding a camel across Desert Island when you spot a sandstorm quickly approaching. When you turn to warn the Elf, she disappears before your eyes! To be fair, she had just finished warning you about ghosts a few minutes ago.

One of the camel's pouches is labeled "maps" - sure enough, it's full of documents (your puzzle input) about how to navigate the desert. At least, you're pretty sure that's what they are; one of the documents contains a list of left/right instructions, and the rest of the documents seem to describe some kind of network of labeled nodes.

It seems like you're meant to use the left/right instructions to navigate the network. Perhaps if you have the camel follow the same instructions, you can escape the haunted wasteland!

After examining the maps for a bit, two nodes stick out: AAA and ZZZ. You feel like AAA is where you are now, and you have to follow the left/right instructions until you reach ZZZ.

This format defines each node of the network individually. For example:

RL

AAA = (BBB, CCC)
BBB = (DDD, EEE)
CCC = (ZZZ, GGG)
DDD = (DDD, DDD)
EEE = (EEE, EEE)
GGG = (GGG, GGG)
ZZZ = (ZZZ, ZZZ)
Starting with AAA, you need to look up the next element based on the next left/right instruction in your input. In this example, start with AAA and go right (R) by choosing the right element of AAA, CCC. Then, L means to choose the left element of CCC, ZZZ. By following the left/right instructions, you reach ZZZ in 2 steps.

Of course, you might not find ZZZ right away. If you run out of left/right instructions, repeat the whole sequence of instructions as necessary: RL really means RLRLRLRLRLRLRLRL... and so on. For example, here is a situation that takes 6 steps to reach ZZZ:

LLR

AAA = (BBB, BBB)
BBB = (AAA, ZZZ)
ZZZ = (ZZZ, ZZZ)
Starting at AAA, follow the left/right instructions. How many steps are required to reach ZZZ?

Your puzzle answer was 21251.

The first half of this puzzle is complete! It provides one gold star: *

--- Part Two ---
The sandstorm is upon you and you aren't any closer to escaping the wasteland. You had the camel follow the instructions, but you've barely left your starting position. It's going to take significantly more steps to escape!

What if the map isn't for people - what if the map is for ghosts? Are ghosts even bound by the laws of spacetime? Only one way to find out.

After examining the maps a bit longer, your attention is drawn to a curious fact: the number of nodes with names ending in A is equal to the number ending in Z! If you were a ghost, you'd probably just start at every node that ends with A and follow all of the paths at the same time until they all simultaneously end up at nodes that end with Z.

For example:

LR

11A = (11B, XXX)
11B = (XXX, 11Z)
11Z = (11B, XXX)
22A = (22B, XXX)
22B = (22C, 22C)
22C = (22Z, 22Z)
22Z = (22B, 22B)
XXX = (XXX, XXX)
Here, there are two starting nodes, 11A and 22A (because they both end with A). As you follow each left/right instruction, use that instruction to simultaneously navigate away from both nodes you're currently on. Repeat this process until all of the nodes you're currently on end with Z. (If only some of the nodes you're on end with Z, they act like any other node and you continue as normal.) In this example, you would proceed as follows:

Step 0: You are at 11A and 22A.
Step 1: You choose all of the left paths, leading you to 11B and 22B.
Step 2: You choose all of the right paths, leading you to 11Z and 22C.
Step 3: You choose all of the left paths, leading you to 11B and 22Z.
Step 4: You choose all of the right paths, leading you to 11Z and 22B.
Step 5: You choose all of the left paths, leading you to 11B and 22C.
Step 6: You choose all of the right paths, leading you to 11Z and 22Z.
So, in this example, you end up entirely on nodes that end in Z after 6 steps.

Simultaneously start on every node that ends with A. How many steps does it take before you're only on nodes that end with Z?

*/

#include <bits/stdc++.h>
using namespace std ;

class Solution1{
    // --- Part 2 ---
public: 
    int getSteps(map<string, pair<string, string>> mp, string moves){
        int n = moves.length();
        cout << "fg1\n";
        vector<string> curr;
        for(auto &it: mp){
            if (it.first[2] == 'A') curr.emplace_back(it.first);
        }
        cout << "fg2\n";

        int count = 0;
        int i = 0; 

        bool flag = true;
        while(flag){
            flag = false;
            
            ++count;
            if (count == 300000) break;
            for(int j = 0; j < curr.size(); ++j) {
                moves[i] == 'L' ? curr[j] = mp[curr[j]].first: curr[j] = mp[curr[j]].second;

                if (curr[j][2] != 'Z') flag = true;
            }
            
            i = (i+1)%n;
        }
        cout << "fg3\n";

        return count;
    }
};

class Solution{
    // --- Part 1 ---
public: 
    int getSteps(map<string, pair<string, string>> mp, string moves){
        int n = moves.length();

        string curr = "AAA";
        int count = 0;

        int i = 0; 

        while(curr != "ZZZ"){
            ++count;
            if (moves[i] == 'L') curr = mp[curr].first;
            else  curr = mp[curr].second;

            i = (i+1)%n;
        }

        return count;
    }
};

int main () {
    string moves;
    cin >> moves;

    map<string, pair<string, string>> mp;

    string node, temp;
    while (cin >> node){
        cin >> temp;

        string f, s;
        cin >> temp;
        f = temp.substr(1, 3);
        cin >> temp;
        s = temp.substr(0, 3);

        mp[node] = pair<string, string>({f, s});
    }

    Solution1 obj;
    cout << obj.getSteps(mp, moves);

    return 0;
}

// TestCase

/* 

LLRRRLRLLRRLLRLRLRLRRLRRRLRRRLRLRRLLRLLRRRLRRLRRRLRLRRRLRRLRLRRRLRRRLRRLRLRRRLRRLRRLRRRLRLRLLRLLRLLRLRRRLRRLRRLRRRLRLRRRLRLRLRLRRRLRRRLRLRLRLRRRLRLLRRLLRLLRRLRRRLLRRRLLRRLRLRRLRLLRLLLLRRLLRRLRRLRLLLRRRLRRLRRRLRRLLRLRRRLRLLRRRLLLLRLRRRLRLRRLRRLRRLLRLRLRRLLLRRLLRLRRLRRRR

HFF = (HRR, BSG)
LJV = (CSH, GDM)
RNF = (QGT, JQL)
CCB = (FTQ, MPQ)
XKL = (HGX, SSQ)
SGN = (MTT, RJK)
MJH = (QBK, GBX)
CNP = (TNH, GHS)
BXM = (SFM, KGF)
RNK = (DJF, THX)
HMS = (JBS, QFS)
VPS = (TXK, SBS)
GBX = (VRK, QCK)
CJP = (XVL, DKG)
RGD = (NQB, NQB)
JMT = (LMD, TCD)
JDB = (LKN, VNH)
XNV = (FLR, SFV)
SDC = (SFV, FLR)
HRR = (HCK, HDM)
CXJ = (VMC, VQB)
HLQ = (CGJ, KBR)
DCQ = (JQX, FMN)
GLN = (JFG, GFD)
MKX = (JTC, RGX)
NBL = (JQM, HKC)
QKM = (QVX, VVN)
BFH = (XHJ, PFM)
SJL = (QNF, PNP)
FXF = (THN, DTL)
BXD = (GLX, SMP)
CNH = (CGP, GTN)
TNC = (BKK, BKK)
JBS = (DCL, DCL)
VQB = (KJL, BJM)
GTJ = (LMS, QBM)
KSM = (NHH, KFX)
VNA = (HRT, NPR)
SPD = (KLM, KLM)
JQM = (MDN, NPJ)
XBD = (JDQ, VQL)
HKC = (NPJ, MDN)
LGB = (VPN, NMP)
RHJ = (LSH, TSM)
RQH = (PTS, HQS)
XVL = (JVP, KRM)
RCR = (XJX, NLM)
RCP = (NRD, DMQ)
MSQ = (SKC, DMS)
VRK = (CQP, FBG)
TPZ = (SHK, QKS)
XVG = (QJX, GTJ)
XVH = (VMQ, LNG)
MHJ = (NSP, QPL)
CSH = (LFJ, VSJ)
SVJ = (VCV, QDC)
DVD = (NQG, BGV)
GJM = (RQC, SHH)
VLK = (RGD, QSQ)
LJT = (HTJ, MVQ)
HQL = (BNP, RPM)
BKT = (GTS, JCR)
SKC = (VKQ, FQR)
KDR = (MTT, RJK)
HKG = (RBH, DCN)
QNB = (TDP, QJN)
CCK = (GRP, NFQ)
FBQ = (CKD, LGG)
KMG = (QRQ, GLT)
LLX = (KGK, BST)
FLF = (LLX, RBP)
HLD = (JRB, PCT)
DMS = (FQR, VKQ)
RBJ = (GJS, JVH)
LRJ = (RPC, RJM)
XHJ = (MBM, QGM)
PTF = (CRS, LTP)
PJN = (GTJ, QJX)
VDQ = (LFC, RVC)
QSM = (KRV, XTX)
FJX = (BHG, HXR)
FNK = (SGK, GND)
HBS = (RPC, RJM)
HGR = (MHM, KLB)
MDX = (VCD, KNP)
HTS = (RTH, DJD)
MNC = (PJR, RHP)
CGK = (HPS, XVH)
GND = (HLD, TMT)
LGN = (BPX, LCP)
RVC = (BHH, XDP)
GRT = (XDF, FMP)
JDQ = (JHD, XJP)
LTV = (FPL, PBT)
TLG = (GHG, DPV)
DBR = (RQH, CRC)
RJK = (JQS, RCR)
FTQ = (NXK, HRH)
PJL = (RJB, VBD)
RTG = (QFN, GMQ)
LQN = (TGN, JPD)
QBP = (SKB, VJK)
GGM = (GTQ, PXK)
XJP = (NSD, QHM)
NCC = (JSQ, KPM)
RXR = (PJN, XVG)
GDM = (LFJ, VSJ)
LMD = (RKB, PPP)
MSB = (JSV, HCH)
FHS = (PHP, FFQ)
NRC = (JDB, LGS)
HBC = (HQL, PJP)
KFX = (VXH, THQ)
XMV = (MHC, RNF)
TGN = (XJF, BNX)
BPB = (LJL, LQC)
GLK = (MQS, SJL)
FLR = (MKC, NBX)
KTG = (SLB, KTT)
KLB = (RXR, TLS)
XBS = (DMQ, NRD)
XKX = (LKD, RFS)
QTL = (QKS, SHK)
MBM = (XBD, MRR)
VDC = (BSP, QLX)
HCM = (FMN, JQX)
DPV = (KMG, GDS)
THC = (JRF, MKX)
BNP = (BFH, LPS)
QKV = (DPH, PFX)
CRS = (HTH, QNB)
TBM = (PJR, RHP)
KVT = (TCD, LMD)
MVQ = (PLF, LNM)
KLM = (MGK, MGK)
TLS = (PJN, XVG)
VXH = (QBF, DJX)
DCL = (RQD, LCJ)
HTJ = (PLF, LNM)
CXP = (XXG, KMD)
FPL = (QKV, CBR)
XJF = (BHQ, TGL)
SHS = (CXJ, QPS)
XLV = (LJT, SRT)
SFV = (MKC, NBX)
FCP = (VKK, LXC)
BNX = (TGL, BHQ)
HCX = (XDF, FMP)
BST = (PSJ, TBF)
VPM = (VPN, NMP)
FBT = (KVT, JMT)
RPM = (LPS, BFH)
FRP = (PDN, QBV)
DMF = (LRX, NNL)
TTR = (LVB, RNX)
LSH = (BJX, CQC)
MRP = (NFQ, GRP)
VCK = (MKH, FVL)
FCK = (KSP, PSM)
HSK = (KLB, MHM)
PFM = (MBM, QGM)
MTT = (JQS, RCR)
SRJ = (NTN, VJX)
GTQ = (XTR, DMN)
ZZZ = (XRL, QKM)
CMB = (HTS, NTL)
KRG = (NDF, HLQ)
CST = (LRM, QXJ)
NQJ = (BPB, JCQ)
CRC = (HQS, PTS)
TMS = (DJK, FBT)
LTP = (QNB, HTH)
CSB = (RNG, GTX)
QDC = (HJD, QVP)
BJM = (DKF, DDK)
SSS = (QJP, CGK)
PLV = (LTM, MLC)
LDJ = (RXM, XJS)
HJG = (NRH, NCC)
SMP = (QFQ, PGX)
NPJ = (NRC, DRT)
STQ = (HTF, NVX)
LKD = (LQF, GCH)
LVL = (VDF, TMH)
DBL = (HVC, VPB)
CGP = (HXF, PFD)
AAA = (QKM, XRL)
XVX = (JBH, BXD)
JQX = (KMB, DCT)
NCH = (DSG, RVG)
NSP = (TVG, SNS)
CKD = (QBP, XRG)
SJM = (NRF, XQK)
SFM = (FHQ, BND)
LTF = (NMC, VFD)
HQS = (HKG, RGR)
JQL = (LQN, FMK)
HJV = (RBP, LLX)
LXT = (SSQ, HGX)
JTP = (KRV, XTX)
FMP = (QSM, JTP)
MDG = (BTV, FCP)
MBX = (HTF, NVX)
TMH = (CJP, PTL)
NVT = (SFM, KGF)
BVQ = (BHS, VDC)
TVG = (MSB, JFQ)
MCB = (GHS, TNH)
RTH = (CXP, NFP)
RJM = (FLF, HJV)
BHG = (VLK, BSH)
JCQ = (LQC, LJL)
SJK = (MPB, MPB)
PSS = (VNX, JKV)
CBK = (HCX, GRT)
MHM = (RXR, TLS)
JCF = (XSN, NHK)
SFH = (MCH, NQD)
MDN = (DRT, NRC)
QFQ = (JVR, PJL)
QFS = (DCL, FTZ)
BHH = (LTV, CLV)
NVX = (FHB, NBL)
BND = (RKS, MKB)
DSG = (NCD, HCN)
FMK = (TGN, JPD)
TSM = (CQC, BJX)
FTZ = (LCJ, RQD)
HRM = (SKC, DMS)
VFF = (BVQ, MSS)
GCG = (PJB, BMC)
QVP = (XFG, RTR)
VQL = (JHD, XJP)
QBV = (DBL, CRL)
PFS = (SPD, SPD)
PBT = (CBR, QKV)
JSQ = (FJX, SDN)
MKC = (RNN, CSJ)
VSJ = (HBN, DVD)
RNN = (BKT, PMV)
FVL = (TBX, VTM)
QBM = (CTP, BQM)
JHD = (QHM, NSD)
GLX = (PGX, QFQ)
LFP = (RTG, SQR)
LFC = (XDP, BHH)
FHQ = (RKS, MKB)
NMP = (QXD, RJT)
QGM = (MRR, XBD)
RHP = (MJH, VNK)
FDP = (KBJ, NLD)
NFQ = (SFH, BDK)
MLC = (PTF, KTH)
PFD = (SRJ, DPF)
VNK = (QBK, GBX)
RQD = (MSQ, HRM)
SDN = (BHG, HXR)
RXM = (PBN, CBK)
RVG = (NCD, HCN)
VGR = (JTX, TXQ)
PGX = (PJL, JVR)
XBR = (CKL, BLJ)
FQR = (XPF, VCP)
RLD = (PHS, BCT)
THQ = (QBF, DJX)
KBN = (RFS, LKD)
CQN = (XBS, RCP)
DCT = (NRM, RDR)
GRP = (SFH, BDK)
RJB = (PKG, FRR)
PSB = (XRD, TCT)
TDP = (VGR, FLB)
JBB = (BXM, NVT)
BHQ = (RBJ, DSL)
VJX = (VFF, TXL)
VRH = (GPX, PVX)
NPX = (KSH, CFG)
HHF = (CKL, BLJ)
TKV = (SBS, TXK)
LTM = (KTH, PTF)
GDS = (QRQ, GLT)
LJL = (HFF, LDK)
QBC = (KBJ, NLD)
NLD = (SVJ, QDF)
PMV = (GTS, JCR)
DTL = (JDR, XJC)
QVX = (SGP, CSB)
HCK = (PSS, FBM)
HVC = (XKX, KBN)
RPQ = (QTL, QTL)
TDC = (XGP, LDJ)
RJT = (NXQ, PQH)
DFB = (MDG, RTL)
CJB = (FBT, DJK)
KBR = (CBD, FVR)
LNG = (XKL, LXT)
QPL = (TVG, SNS)
KTZ = (NPR, HRT)
NPR = (CDL, QVT)
RPC = (HJV, FLF)
GHP = (BCT, PHS)
TCT = (KLN, GLK)
VTM = (HDG, TVV)
VDF = (PTL, CJP)
QDF = (QDC, VCV)
NTL = (DJD, RTH)
KGF = (FHQ, BND)
NSD = (VLS, TLG)
DRG = (JCF, SDL)
BHL = (NVT, BXM)
QQC = (RVG, DSG)
MCZ = (GLN, NFK)
KCM = (PDM, NQJ)
DJX = (TNX, QMP)
GLL = (HHB, LLN)
DJD = (CXP, NFP)
JPD = (XJF, BNX)
CVX = (GMN, MSX)
DSL = (GJS, JVH)
LGG = (XRG, QBP)
GLT = (LGB, VPM)
XLP = (DQX, VDQ)
TGL = (DSL, RBJ)
MRR = (VQL, JDQ)
LKS = (KFS, CXQ)
LLN = (XHD, GQB)
RTR = (KRG, PVF)
CKR = (VMS, FPR)
PTS = (RGR, HKG)
PVX = (CKB, BHK)
JPK = (XRD, TCT)
GTX = (QKH, GJM)
MPB = (MHJ, MHJ)
QJP = (XVH, HPS)
FXV = (QKM, XRL)
XRG = (SKB, VJK)
QHM = (VLS, TLG)
PSJ = (TMP, BXG)
XDF = (JTP, QSM)
NFK = (GFD, JFG)
QJX = (LMS, QBM)
TXQ = (FVD, SJM)
XMH = (SJK, SJK)
HBN = (NQG, NQG)
QVN = (XGP, LDJ)
VNX = (XNM, RNH)
FBG = (CJB, TMS)
RNH = (CNK, NBF)
RBP = (BST, KGK)
LRX = (SGN, KDR)
LGS = (LKN, VNH)
GXS = (NCJ, BJG)
QSQ = (NQB, PBM)
VMS = (FXV, FXV)
LPS = (PFM, XHJ)
BLJ = (RNK, HNG)
QBK = (VRK, QCK)
QRM = (KSM, GVB)
JFG = (FDP, QBC)
LCP = (NPX, MQX)
KJG = (MLC, LTM)
HGX = (RJG, GCG)
GBP = (PVX, GPX)
MPX = (TKF, SHS)
KJL = (DDK, DKF)
JQS = (XJX, NLM)
KTH = (CRS, LTP)
XGP = (RXM, XJS)
CKB = (BQB, HBC)
JSR = (HVQ, GHR)
QXD = (PQH, NXQ)
HXF = (DPF, SRJ)
GHS = (FVK, LTK)
SKB = (CMB, DBB)
XFG = (PVF, KRG)
NRF = (FNS, XPS)
PTL = (DKG, XVL)
KMK = (QXJ, LRM)
GMN = (MDX, XFS)
GLQ = (LRX, NNL)
XDP = (LTV, CLV)
NDF = (KBR, CGJ)
KVL = (XLV, NPT)
PHS = (JPK, PSB)
QTS = (MKH, FVL)
PLJ = (PSM, KSP)
FVK = (HGR, HSK)
LXC = (LDG, FNQ)
TBX = (TVV, HDG)
HVF = (NPT, XLV)
GNT = (KMK, CST)
MKB = (KVL, HVF)
QCK = (CQP, FBG)
VPK = (FFQ, PHP)
BDX = (NCC, NRH)
SGK = (HLD, TMT)
XJD = (DMM, GNT)
TXK = (GGM, KQM)
XQK = (FNS, XPS)
PPP = (CSQ, MBK)
XXG = (QTS, VCK)
XTX = (HVK, LJV)
QJN = (FLB, VGR)
SNS = (MSB, JFQ)
DPA = (NSP, QPL)
RGX = (SLN, KXT)
DPF = (NTN, VJX)
HRK = (XJV, NMB)
MRQ = (MHC, RNF)
CFG = (RHJ, DML)
KPM = (SDN, FJX)
CKL = (HNG, RNK)
RRX = (XBS, RCP)
HRH = (JKH, RXD)
SSQ = (RJG, GCG)
SLV = (NMB, XJV)
JPA = (NFK, GLN)
LCJ = (HRM, MSQ)
QKS = (XNV, SDC)
BSQ = (CNP, MCB)
BQJ = (CNP, MCB)
PNP = (QVN, TDC)
LQF = (CPG, LBB)
FFJ = (RLD, GHP)
DPH = (VPK, FHS)
JKH = (BKD, JKQ)
BSG = (HCK, HDM)
KFS = (MSL, RXC)
HTH = (QJN, TDP)
TCX = (SLB, KTT)
DDK = (KNN, FXF)
TNH = (LTK, FVK)
PSC = (SDL, JCF)
HRT = (CDL, QVT)
PHP = (SGJ, DBR)
TMM = (BXD, JBH)
TCD = (PPP, RKB)
PDM = (BPB, JCQ)
SLB = (LRJ, HBS)
DJK = (KVT, JMT)
NRD = (VRH, GBP)
DKG = (KRM, JVP)
JVH = (BDX, HJG)
DKF = (FXF, KNN)
CNK = (QNG, LKS)
PSM = (HBX, THC)
BDK = (MCH, NQD)
FFT = (QTL, TPZ)
PDN = (DBL, CRL)
TMP = (LFP, VVX)
KBJ = (SVJ, QDF)
KLT = (LGG, CKD)
KQM = (GTQ, PXK)
JKS = (MPB, PTD)
GNK = (NFK, GLN)
RJF = (SMT, JSR)
QXJ = (VPS, TKV)
PBN = (GRT, HCX)
FQQ = (MPQ, FTQ)
PCT = (CFL, CGR)
HNG = (DJF, THX)
RNX = (VDD, FNK)
GVB = (KFX, NHH)
QRQ = (VPM, LGB)
RNG = (QKH, GJM)
CXQ = (MSL, RXC)
XRD = (KLN, GLK)
TPL = (GMN, MSX)
MKH = (VTM, TBX)
XPS = (NSV, RJF)
CTP = (DFB, FKQ)
NRM = (XLP, MLG)
DBB = (NTL, HTS)
XJV = (GKC, XBM)
DBA = (QKS, SHK)
XJC = (SBL, NQL)
NQD = (CCR, LGN)
CGR = (CNH, JCN)
CHF = (TMM, XVX)
JSV = (BQJ, BSQ)
CGJ = (FVR, CBD)
CSJ = (PMV, BKT)
LMS = (BQM, CTP)
HCH = (BQJ, BSQ)
VMC = (BJM, KJL)
CCR = (LCP, BPX)
NPT = (LJT, SRT)
SLN = (LTF, GFL)
XRL = (VVN, QVX)
QTK = (MRQ, XMV)
PJP = (BNP, RPM)
XBM = (DBD, FSJ)
QNG = (KFS, CXQ)
BHS = (QLX, BSP)
NQG = (GNK, GNK)
XJX = (XRX, QRM)
SDL = (XSN, NHK)
MSS = (VDC, BHS)
KRV = (LJV, HVK)
CBR = (DPH, PFX)
HCN = (GLQ, DMF)
JCN = (CGP, GTN)
PFX = (FHS, VPK)
NSV = (JSR, SMT)
NMB = (GKC, XBM)
XFS = (KNP, VCD)
SHH = (STV, RQK)
LVB = (VDD, FNK)
VKQ = (XPF, VCP)
KLN = (SJL, MQS)
GHR = (MRP, CCK)
NPG = (CCL, LVL)
CSQ = (PFS, DNH)
SMT = (HVQ, GHR)
MQS = (QNF, PNP)
DFF = (QJP, CGK)
DNH = (SPD, BNT)
DBD = (PGR, NPG)
LQC = (HFF, LDK)
KSH = (DML, RHJ)
NMC = (FFJ, NDD)
NQL = (STQ, MBX)
JVR = (RJB, VBD)
BKK = (JBS, JBS)
CLV = (FPL, PBT)
QGT = (FMK, LQN)
GFD = (QBC, FDP)
VKK = (LDG, FNQ)
TVV = (DRG, PSC)
NXQ = (CCB, FQQ)
HPS = (LNG, VMQ)
SGP = (GTX, RNG)
QMP = (GRL, MCJ)
GTN = (HXF, PFD)
VJK = (CMB, DBB)
VVX = (RTG, SQR)
HJD = (XFG, RTR)
BHK = (HBC, BQB)
GCH = (CPG, LBB)
LRM = (TKV, VPS)
DQX = (LFC, RVC)
BJX = (TPL, CVX)
JKQ = (GLL, VHH)
GFL = (NMC, VFD)
RJG = (PJB, BMC)
BSH = (RGD, QSQ)
VFD = (FFJ, NDD)
HVQ = (MRP, CCK)
KGK = (PSJ, TBF)
CPG = (KTG, TCX)
FMN = (KMB, DCT)
MSL = (DVC, QTK)
SRT = (HTJ, MVQ)
BQM = (DFB, FKQ)
TBF = (BXG, TMP)
RQC = (RQK, STV)
GMQ = (DFF, SSS)
SBL = (MBX, STQ)
GKC = (DBD, FSJ)
TKF = (QPS, CXJ)
KTT = (HBS, LRJ)
VCP = (XPD, FRP)
PJR = (MJH, VNK)
VCD = (RRX, CQN)
FFQ = (DBR, SGJ)
VCV = (HJD, QVP)
PLF = (LQM, KCM)
FLB = (TXQ, JTX)
RFS = (LQF, GCH)
XRX = (KSM, GVB)
BTV = (VKK, LXC)
DMM = (CST, KMK)
KMB = (RDR, NRM)
JRF = (JTC, RGX)
QVT = (SLV, HRK)
DCN = (XMH, SSP)
TNX = (GRL, MCJ)
NRH = (JSQ, KPM)
PJB = (QQC, NCH)
BJN = (PLJ, FCK)
MCJ = (TNC, QLS)
DML = (LSH, TSM)
PVF = (HLQ, NDF)
GHG = (KMG, GDS)
CQC = (CVX, TPL)
KNN = (THN, DTL)
RKB = (CSQ, MBK)
MSX = (MDX, XFS)
BPX = (MQX, NPX)
JTX = (FVD, SJM)
GQB = (CHF, JFK)
BSP = (BHL, JBB)
DMQ = (VRH, GBP)
NHH = (VXH, THQ)
CKQ = (NCJ, BJG)
QFN = (DFF, SSS)
SBS = (KQM, GGM)
PBM = (RPQ, FFT)
TXL = (MSS, BVQ)
MQX = (KSH, CFG)
CQP = (CJB, TMS)
FKQ = (MDG, RTL)
FVR = (JTF, BJN)
RQK = (PLV, KJG)
SSK = (GNT, DMM)
VPN = (RJT, QXD)
KNP = (RRX, CQN)
JDR = (SBL, NQL)
BQB = (PJP, HQL)
PQL = (MGK, KTZ)
MBK = (PFS, DNH)
DVC = (MRQ, XMV)
LNM = (LQM, KCM)
LDK = (BSG, HRR)
VBD = (PKG, FRR)
FVD = (XQK, NRF)
BKD = (GLL, VHH)
NDD = (GHP, RLD)
QSV = (VMS, VMS)
MLG = (VDQ, DQX)
RGR = (RBH, DCN)
KSP = (THC, HBX)
NQB = (RPQ, RPQ)
QNF = (QVN, TDC)
MGK = (HRT, NPR)
HVK = (CSH, GDM)
LFJ = (HBN, HBN)
JTF = (PLJ, FCK)
RDR = (MLG, XLP)
SQR = (QFN, GMQ)
QJA = (RQD, LCJ)
RTL = (BTV, FCP)
LQM = (PDM, NQJ)
XTR = (HHF, XBR)
GRL = (TNC, QLS)
JCR = (GNC, TTR)
KXT = (LTF, GFL)
CRL = (HVC, VPB)
PQH = (CCB, FQQ)
CDL = (SLV, HRK)
BJG = (HCM, DCQ)
BGV = (GNK, MCZ)
DRT = (JDB, LGS)
NLM = (QRM, XRX)
GNC = (RNX, LVB)
DJF = (TBM, MNC)
BMC = (NCH, QQC)
HHB = (XHD, GQB)
SHK = (XNV, SDC)
GJS = (HJG, BDX)
QLS = (BKK, HMS)
MHC = (QGT, JQL)
FHB = (HKC, JQM)
LDG = (FBQ, KLT)
QLX = (BHL, JBB)
CCL = (TMH, VDF)
XHD = (CHF, JFK)
PXK = (DMN, XTR)
LKN = (SSK, XJD)
KMD = (QTS, VCK)
HBX = (JRF, MKX)
KRM = (MPX, SDB)
VLS = (DPV, GHG)
JRB = (CFL, CGR)
NHK = (GXS, CKQ)
FBM = (VNX, JKV)
NCD = (DMF, GLQ)
RBH = (XMH, SSP)
PTD = (MHJ, GGZ)
LTK = (HSK, HGR)
JBH = (GLX, SMP)
FNQ = (FBQ, KLT)
JFQ = (JSV, HCH)
JFK = (TMM, XVX)
DMN = (XBR, HHF)
NBF = (QNG, LKS)
GPX = (BHK, CKB)
RXD = (BKD, JKQ)
JVP = (MPX, SDB)
HTF = (FHB, NBL)
MPQ = (NXK, HRH)
VDD = (GND, SGK)
NXK = (RXD, JKH)
CBD = (JTF, BJN)
MCH = (CCR, LGN)
VNH = (XJD, SSK)
CFL = (JCN, CNH)
TMT = (JRB, PCT)
XJS = (CBK, PBN)
LBB = (TCX, KTG)
PGR = (LVL, CCL)
RXC = (QTK, DVC)
THN = (XJC, JDR)
JKV = (RNH, XNM)
HDG = (PSC, DRG)
SGJ = (CRC, RQH)
VHH = (HHB, LLN)
THX = (TBM, MNC)
NCJ = (HCM, DCQ)
NTN = (TXL, VFF)
QKH = (RQC, SHH)
VPB = (XKX, KBN)
XSN = (CKQ, GXS)
PKG = (QSV, QSV)
FNS = (RJF, NSV)
FSJ = (NPG, PGR)
HXR = (VLK, BSH)
BXG = (VVX, LFP)
BCT = (PSB, JPK)
QPS = (VQB, VMC)
XNM = (NBF, CNK)
NBX = (CSJ, RNN)
FRR = (QSV, CKR)
QBF = (QMP, TNX)
FPR = (FXV, ZZZ)
RKS = (KVL, HVF)
SSP = (SJK, JKS)
GGZ = (QPL, NSP)
STV = (PLV, KJG)
VMQ = (XKL, LXT)
JTC = (SLN, KXT)
GTS = (TTR, GNC)
XPD = (QBV, PDN)
VVN = (SGP, CSB)
NFP = (KMD, XXG)
BNT = (KLM, PQL)
SDB = (TKF, SHS)
XPF = (XPD, FRP)
HDM = (PSS, FBM)
NNL = (KDR, SGN)

*/