// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutonDrive.h"
#define THRESHOLD .05
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutonDrive::AutonDrive(double goalDistance): Command() {
    m_goalDistance = goalDistance;
    m_currentDistance = 0;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutonDrive::Initialize() {
	RobotMap::driveTraindriveEncoder->Reset();
	printf(" autondrive init \n\n\n\n\n\n\n\n\n\\n\n\n\n\n\n\n\n");

}

// Called repeatedly when this Command is scheduled to run
void AutonDrive::Execute() {
	m_currentDistance = RobotMap::driveTraindriveEncoder->GetDistance();
	float power =  (-1 / m_goalDistance) * m_currentDistance + 1;
	printf("power = %f" , power);
	//Phillip, we changed this because it was creating an error: goalDistance --> m_goalDistance
	//Tell us if this is incorrect - Tommy & Elliott
	RobotMap::driveTrainRobotDrive41->TankDrive(-power/4,-power/4);
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDrive::IsFinished() {
    return (fabs(m_currentDistance - m_goalDistance) < THRESHOLD);
}

// Called once after isFinished returns true
void AutonDrive::End() {
	RobotMap::driveTraindriveEncoder->Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDrive::Interrupted() {
	End();
}
