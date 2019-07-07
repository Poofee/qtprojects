% 20190707 by Poofee
% 测试gmsh对不同位移的分网，不可压缩区域是否不变
disp = 0;
mindisp = 0;
maxdisp = 6e-3;
step = 1e-3;
close all;
figure;
axis equal;
for i=1:maxdisp/step
    disp = step*i;
    cmd = ['gmsh.exe -setnumber disp ', num2str(disp),' -2 -format msh2 model.geo '];
    system(cmd);
    
    pause(10);
    mesh = load_gmsh2('model.msh');
    
    for j=1:mesh.nbTriangles
        if(mesh.ELE_TAGS(mesh.nbElm-mesh.nbTriangles+j,2) ~= 2)
            continue;
        end
        n = mesh.TRIANGLES(j,1:3);
        
        plot(mesh.POS(n,1),mesh.POS(n,2),'*-');
        hold on;
    end
    axis equal
end
