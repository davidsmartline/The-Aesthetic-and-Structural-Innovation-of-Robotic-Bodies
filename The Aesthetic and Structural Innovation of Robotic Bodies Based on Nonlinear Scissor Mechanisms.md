
The Aesthetic and Structural Innovation of Robotics Bodies 
David Jian Tang, Smart Line Robotic Inc., Raleigh, NC27604, USA, and Yiping Tang,School of Computer Science,Hunan Normal University, Changsha, Hunan Province, China.

Abstract
This paper proposes a novel robotic body based on a nonlinear scissor mechanism with forward bending and gradient link lengths. By introducing a non-uniform geometric configuration into the conventional scissor structure, a conical spatial topology is formed, effectively overcoming the inherent base contraction issue observed in traditional linear scissor mechanisms during horizontal extension.
The proposed structure achieves a combination of high stiffness, large workspace, high payload capacity, and low energy consumption. Experimental results demonstrate that the relationship between actuator displacement and end-effector displacement can be approximated as a linear function. Compared with traditional articulated robots, which rely on complex high-order nonlinear kinematic models, the proposed system simplifies the kinematics into a first-order linear equation, significantly reducing control complexity.
Furthermore, the structure eliminates the need for high-precision reducers, offering advantages such as low cost, structural simplicity, and suitability for confined workspace applications. This research introduces a new paradigm for next-generation robotic body design.

Index Terms
Nonlinear scissor mechanism, robotic structure, kinematics, telescopic arm, robotic design

I. Introduction
Robotic manipulators are widely used in industrial automation, medical systems, rehabilitation, and service industries. With the rapid integration of artificial intelligence and physical systems, robotics is entering a new era of expansion.
Traditional robotic arms typically adopt articulated joint structures driven by electric, pneumatic, or hydraulic actuators [1]. However, such systems require high-ratio precision reducers, leading to high manufacturing cost and complexity [2]. Additionally, the use of precision gear systems increases weight and volume, reduces payload efficiency, and complicates installation and maintenance [3].
Moreover, the forward and inverse kinematics of articulated robots involve complex nonlinear equations [4], increasing computational cost and limiting accessibility for broader engineering applications.
To address these challenges, this paper introduces a nonlinear scissor-based telescopic robotic arm. The key innovation lies in:
•	Forward-bent links
•	Gradually decreasing link lengths
•	Conical spatial configuration
This design ensures that the base span does not shrink during extension, thereby overcoming instability issues inherent in traditional scissor mechanisms and significantly improving load capacity and structural stability.

II. System Design
A. Overall Architecture
The proposed robot consists of:
•	Conical telescopic arm
•	End-effector
•	Drive system
•	Column support
•	Rotational base
The telescopic arm serves as the core execution unit, with internal actuation mechanisms driving extension and contraction.
Fig.1 Long-arm robot


B. Conical Telescopic Arm
The arm is composed of multiple scissor units and a semi-scissor unit connected in series:
•	Each scissor unit consists of two hinged links
•	Adjacent units are connected via pivot joints
•	The semi-scissor unit provides terminal constraint
Key structural characteristics include:
1.	Link lengths decrease monotonically from base to tip
2.	Each link exhibits forward bending
3.	Bending angles vary gradually along the arm
4.	The entire structure forms a conical topology (0°–80°)

C. Kinematics and Inverse Kinematics
Unlike traditional articulated robots, whose kinematics are highly nonlinear, experimental results reveal that the proposed structure exhibits an approximately linear mapping between input and output.
Fig.2  The Relationship of Driving and Moving Data

The fitted relationship is:
   y = 5.127x - 47.425
The inverse function is:

     x = 0.194y + 9.28
This linearization significantly reduces computational complexity, enabling high-precision control using low-cost controllers.
Further analysis indicates that:
•	The average transmission ratio ≈ 512.7
•	Local transmission ratio increases with stroke
This non-uniform amplification behavior is attributed to the conical gradient geometry, which improves load distribution and mechanical efficiency.

D. Experimental Setup and Validation
Prototype specifications:
•	Arm length: 3.5 m
•	Payload: 25 kg
•	Actuation: electric cylinder with encoder feedback
Experimental data confirm:
•	Near-linear displacement mapping
•	Increasing local transmission ratio along extension
This phenomenon demonstrates that structural symmetry leads to simplified kinematics despite geometric complexity.

III. Working Principle
The robot operates by actuating relative motion between adjacent scissor units, resulting in synchronized extension or contraction.
Key characteristics:
•	Linear motion output
•	Triangular support-like stability
•	Wide base for stiffness
•	Narrow tip for confined workspace
The actuator stroke is only 5%–10% of total extension, significantly reducing actuator size and system cost.










Fig.3  The prototype of the Lang-arm robot based on non-linear scissors structure









Fig.4  The prototype of the heavy duty robot based on non-linear scissors structure
IV. Advantages
1) High Stability and Load Capacity
The conical symmetric structure enhances rigidity and load-bearing capability.
2) Ultra-Low Energy Consumption
Compared with conventional robots requiring kilowatt-level motors, the proposed system operates at approximately 50 W, due to:
•	Planar motion (no gravity compensation)
•	Reduced rotational inertia
3) No Precision Reducers Required
Eliminates ~40% of robot cost associated with reducers.
4) Simplified Control Algorithms
Linear kinematics enable accessibility even for low-level developers, greatly expanding adoption.
5) Robots of different sizes and shapes can be constructed in a modular fashion. 
Single scissor-type modules can be connected in series or parallel to construct various types of robots, even heavy duty robots. For example in Fig.3, It used less scissor-type modules to construct a compact robot as well. 

Fig.5 Compact robot
6）Construct multiple hands on long arm robot
Install one or more wrist robots on the end of a long-arm robot or different place of it for various applications as Fig.6.

Fig.6  A wrist hand on long arm robot



V. Conclusion
This paper presents a nonlinear gradient scissor-based robotic arm with a conical topology. The design overcomes the fundamental limitation of traditional scissor mechanisms and simplifies the complex nonlinear kinematics of conventional robots into a first-order linear model.
The system achieves:
•	Stable extension
•	High payload capacity
•	Low energy consumption
•	Simplified control
Future work will explore additional nonlinear scissor configurations, including spherical, ellipsoidal, cylindrical, and modular forms, enabling a wide range of robotic applications.


References
[1] Q. Wang, Design and Analysis of Industrial Manipulators, 2014.
[2] Y. Li and Z. Chen, “Low-cost design of joint robots,” Manufacturing Systems, vol. 35, pp. 89–96, 2015.
[3] H. Zhang, “Heavy-duty telescopic manipulators,” Journal of Mechanical Engineering, vol. 50, no. 11, pp. 1–8, 2014.
[4] J. Craig, Introduction to Robotics: Mechanics and Control, 3rd ed. Beijing: China Machine Press, page101, 2019.
[5] J. D. Smith and A. M. Johnson, “Scissor mechanisms in engineering,” J. Mechanical Design, 2018.
[6] Y. Li et al., “Deformation characteristics of scissor trusses,” JCSR, 2020.
[7] R. Garcia and J. Martinez, “Telescopic structures for aerospace,” Acta Astronautica, 2019.
[8] W. Chen et al., “Cube-like modular structures,” Construction Materials, 2021.
[9] T. Brown and S. Davis, “Intelligent telescopic structures,” IEEE/ASME Trans. Mechatronics, 2022.

