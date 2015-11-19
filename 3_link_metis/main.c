#include <stdio.h>

#include "metis.h"

#define NVTXS 19
#define NEDGES 18

int main()
{
    // =====================================
    // Set Metis inputs values.
    // =====================================

    // The number of vertices in the graphs.
    idx_t nvtxs = NVTXS;

    // The number of balancing constraints. It should be at least 1.
    idx_t ncon = 1;

    // The adjacency structure of the graph.
    idx_t xadj[NVTXS+1] = {
         0,  //  0
         4,  //  1
         5,  //  2
         6,  //  3
         7,  //  4
         9,  //  5
        11,  //  6
        14,  //  7
        16,  //  8
        21,  //  9
        22,  // 10
        23,  // 11
        24,  // 12
        25,  // 13
        27,  // 14
        29,  // 15
        33,  // 16
        34,  // 17
        35,  // 18
        36}; // 19

    idx_t adjncy[NEDGES*2] = {
        1, 2, 3, 4,        //  0: [ 0: 4]
        0,                 //  1: [ 4: 5]
        0,                 //  2: [ 5: 6]
        0,                 //  3: [ 6: 7]
        0, 5,              //  4: [ 7: 9]
        4, 6,              //  5: [ 9:11]
        7, 5, 13,          //  6: [11:14]
        8, 6,              //  7: [14:16]
        9, 10, 11, 12, 7,  //  8: [16:21]
        8,                 //  9: [21:22]
        8,                 // 10: [22:23]
        8,                 // 11: [23:24]
        8,                 // 12: [24:25]
        6, 14,             // 13: [25:27]
        13, 15,            // 14: [27:29]
        16, 17, 18, 14,    // 15: [29:33]
        15,                // 16: [33:34]
        15,                // 17: [34:35]
        15};               // 18: [35:36]

    // The weights of the vertice.
    idx_t *vwgt = NULL;

    // The size of the vertices for computing the total communication volume.
    idx_t *vsize = NULL;

    // This is an array of size nparts×ncon that specifies the desired weight
    // for each partition and constraint.
    idx_t *adjwgt = NULL;

    // The number of parts to partition the graph.
    idx_t nparts = 3;

    // This is an array of size nparts×ncon that specifies the desired weight
    // for each partition and constraint.
    real_t *tpwgts = NULL;

    // This is an array of size ncon that specifies the allowed load imbalance
    // tolerance for each constraint.
    real_t *ubvec = NULL;

    // This is the array of option;
    idx_t *options = NULL;

    // =====================================
    // Allocate Metis outputs.
    // =====================================

    // Edge-cut or the total communication volume of the partitioning
    // solution.
    idx_t objval;

    // This is a vector of size nvtxs that upon successful completion stores
    // the partition vector of the graph
    idx_t part[NVTXS];

    // =====================================
    // Call Metis function.
    // =====================================

    int err = METIS_PartGraphKway(&nvtxs, &ncon, xadj, adjncy,
                                  vwgt, vsize, adjwgt, &nparts, tpwgts,
                                  ubvec, options, &objval, part);

    // =====================================
    // Print Metis results.
    // =====================================

    switch (err)
    {
    case METIS_OK:
        break;
    case METIS_ERROR_INPUT:
        fprintf(stderr, "error input\n");
        return 1;
        break;
    case METIS_ERROR_MEMORY:
        fprintf(stderr, "error memory\n");
        return 1;
        break;
    case METIS_ERROR:
        fprintf(stderr, "error\n");
        return 1;
        break;
    default:
        fprintf(stderr, "Unexpected return value: %d\n", err);
        return 1;
        break;
    }

    printf("objval: %d\n", objval);

    printf("part: ");
    idx_t i;
    for (i= 0 ; i < nvtxs ; i++)
        printf("%d ", part[i]);
    printf("\n");

    return 0;
}
