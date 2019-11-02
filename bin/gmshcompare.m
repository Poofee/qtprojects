% 20190707 by Poofee
% 测试gmsh对不同位移的分网，不可压缩区域是否不变

% 区域编号
MAG_CIR = [1,3,4];
COIL = [2];
AIR = [7];
MOBIL_AIR = [6];
CORE = [5];
INFINITE = [8];

disp = 0;
mindisp = 0;
maxdisp = 6e-3;
step = 1e-3;

close all;


% 测试分网
for i=0:maxdisp/step
    disp = step*i;
    cmd = ['gmsh.exe -setnumber disp ', num2str(disp),' -2 -format msh2 model.geo '];
    system(cmd);
    
    pause(10);
    mesh = load_gmsh2('model.msh');
    
    for j=1:mesh.nbTriangles
        if(find(CORE == mesh.ELE_TAGS(mesh.nbElm-mesh.nbTriangles+j,2)))
            n = mesh.TRIANGLES(j,1:3);
            
            plot(mesh.POS(n,1),mesh.POS(n,2)+disp,'*-');
            hold on;
        end        
    end
    axis equal
    title(['step: ',num2str(i)]);
end


