module railbase() {
	polygon(points=[[1,0],[1,-5.25],[-5.25,-5.25],[-5.25,2.25],[-12,2.25],[-12,32.5],[2,32.5],[2,26],[1.5,26],[-0.25,30],[-9.25,30],[-9.25,4.75],[-3,4.75],[-3,-3],[0,-3],[0,0]]);
}

module railext1() {
	linear_extrude(height=0.01)
	polygon(points=[[-3,2.25],[-12,2.25],[-12,32.5],[2,32.5],[2,26]]);
}

module railint1() {
	linear_extrude(height=0.01)
		polygon(points=[[2,26],[1.5,26],[-0.25,30],[-9.25,30],[-9.25,4.75],[-3,4.75]]);
}

module railext2() {
	linear_extrude(height=0.01)
	polygon(points=[[1,0],[1,-5.25],[-5.25,-5.25],[-5.25,4.75]]);
}

module railint2() {
	linear_extrude(height=0.01)
		polygon(points=[[-3,4.75],[-3,-3],[0,-3],[0,0]]);
}

module rail(rlength) {
	linear_extrude(height=rlength)
		railbase();
}

module railtaper(taperwid,offset) {
	hull() {
		translate([0,0,offset-taperwid]) railint1();
		translate([0,0,offset+taperwid]) railext1();
	}
	hull() {
		translate([0,0,offset-taperwid]) railint2();
		translate([0,0,offset+taperwid]) railext2();
	}
}

difference() {
	rail(60);
	railtaper(10,65);
}

translate([-5,13.75,-1.25]) cube(size=[18,42,2.51],center=true);

translate([3.25,21.125,-3.75]) difference(){
	cube(size=[45.5,56.75,2.51],center=true);
	hull(){
		translate([-18.75,24.375,-1]) cylinder(h=6,r=1.4,center=true);
		translate([-11.25,24.375,-1]) cylinder(h=6,r=1.4,center=true);
	}
	translate([18.75,-20.875,-1]) cylinder(h=6,r=3.85/2,center=true);
}
	