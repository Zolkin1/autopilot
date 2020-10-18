#include <Eigen/Dense>

void stateEstimationThread();

struct state
{
    float x;
    float y;
    float z;

    Eigen::Matrix3f rotMat;
};
