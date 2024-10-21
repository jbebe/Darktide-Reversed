#pragma once

#include <vector>
#include <cstdio>

#include "Allocator.h"
#include "IdString.h"
#include "MeshGeometry.h"
#include "SkinData.h"
#include "LODObjectData.h"
#include "TerrainData.h"
#include "SortMap.h"
#include "less.h"
#include "ActorResource.h"
#include "JointDesc.h"
#include "MoverDesc.h"
#include "ScriptMethod.h"
#include "MeshObject.h"
#include "DynamicData.h"
#include "Camera.h"
#include "Light.h"
#include "VehicleResource.h"
#include "InputArchive.h"
#include "StrongPointerSerializer.h"

namespace stingray {
    struct UnitResource {
        Allocator* _allocator;
        TraceAllocator _mesh_geometry_allocator;
        IdString64 _resource_name;
        IdString64 _skeleton_name;
        Vector<MeshGeometry*> _mesh_geometries;
        Vector<SkinData*> _skins;
        Vector<LODObjectData*> _lod_objects;
        Vector<TerrainData*> _terrains;
        IdString64 _default_material_resource;
        SortMap<IdString32, IdString64, less> _materials;
        Array<char> _mesh_geometry_triangle_finder;
        Array<char> _simple_animation;
        SortMap<IdString32, Vector<int>, less> _simple_animation_groups;
        Vector<ActorResource*> _actors;
        Vector<JointDesc> _joints;
        Vector<MoverDesc> _movers;
        //unit_resource::PhysXAllocator _physics_scene_data_allocator;
        Array<char> _physics_scene_data;
        //unit_resource::PhysXAllocator _physics_scene_data_allocator_64bit;
        Array<char> _physics_scene_data_64bit;
        Array<char> _apex_data;
        SortMap<IdString32, ScriptMethod, less> _script_events;
        bool _has_animation_blender_bones;
        DynamicString _animation_state_machine;
        SortMap<IdString32, Vector<unsigned int>, less> _visibility_groups;
        Array<char> _flow;
        Array<char> _flow_dynamic_data;
        bool _flow_dynamic_data_patched;
        SceneGraph _scene_graph;
        Vector<MeshObject*> _meshes;
        DynamicData _dynamic_data;
        Vector<Camera*> _cameras;
        Vector<Light*> _lights;
        Vector<VehicleResource*> _vehicles;

        static void parse(const std::vector<char>& archive) {
            UnitResource resource{};

            
            int version = ((int*)archive.data())[0];
            if ((version - 10900209) & 0xFFFEFFFF) {
                printf(
                    "A version error was found in the compiled `%s` data. The engine wants version `%u`,\n"
                    "but found version `%u` on disk. This means there is a mismatch between the data compiler\n"
                    "and the engine.\n"
                    "\n"
                    "If you are building your own executables, make sure to rebuild both the data compiler and the\n"
                    "engine runtime and recompile your data. That should fix the issue.\n"
                    "\n"
                    "As a last resort, if you can't find any other way of getting rid of this error, you can\n"
                    "try to delete your data folder and recompile everything from scratch.",
                    "unit",
                    10965745, 0);
            }
            else {
                printf("Check OK");
            }


            StrongPointerVectorSerializer<MeshGeometry>::serialize(&v10, v2);
        }

        /*
        void __fastcall serialize(InputArchive* s)
        {
            InputArchive* v2; // rdi@1
            UnitResource* v3; // rbx@1
            const char* v4; // rax@2
            const char* v5; // rax@4
            const char* v6; // rax@6
            const char* v7; // rax@8
            unsigned int* v8; // rsi@9
            const char* v9; // rax@10
            StrongPointerVectorSerializer<MeshGeometry> v10; // [sp+20h] [bp-39h]@1
            StrongPointerVectorSerializer<SkinData> v11; // [sp+30h] [bp-29h]@1
            StrongPointerVectorSerializer<MeshObject> v12; // [sp+40h] [bp-19h]@1
            StrongPointerVectorSerializer<ActorResource> v13; // [sp+50h] [bp-9h]@1
            StrongPointerVectorSerializer<Camera> v14; // [sp+60h] [bp+7h]@1
            StrongPointerVectorSerializer<Light> v15; // [sp+70h] [bp+17h]@1
            StrongPointerVectorSerializer<LODObjectData> v16; // [sp+80h] [bp+27h]@1
            StrongPointerVectorSerializer<TerrainData> v17; // [sp+90h] [bp+37h]@1
            StrongPointerVectorSerializer<VehicleResource> v18; // [sp+A0h] [bp+47h]@1
            int buffer; // [sp+C0h] [bp+67h]@1

            buffer = 10965745;
            v10.v = &this->_mesh_geometries;
            v2 = s;
            v10.a = this->_mesh_geometries._allocator;
            v3 = this;
            v11.v = &this->_skins;
            v11.a = this->_skins._allocator;
            v12.v = &this->_meshes;
            v12.a = this->_meshes._allocator;
            v13.v = &this->_actors;
            v13.a = this->_actors._allocator;
            v18.v = &this->_vehicles;
            v18.a = this->_vehicles._allocator;
            v14.v = &this->_cameras;
            v14.a = this->_cameras._allocator;
            v15.v = &this->_lights;
            v15.a = this->_lights._allocator;
            v16.v = &this->_lod_objects;
            v16.a = this->_lod_objects._allocator;
            v17.v = &this->_terrains;
            v17.a = this->_terrains._allocator;
            InputArchive::read(s, &buffer, 4u);
            if ((buffer - 10900209) & 0xFFFEFFFF)
            {
                v4 = eprintf(
                    "A version error was found in the compiled `%s` data. The engine wants version `%u`,\n"
                    "but found version `%u` on disk. This means there is a mismatch between the data compiler\n"
                    "and the engine.\n"
                    "\n"
                    "If you are building your own executables, make sure to rebuild both the data compiler and the\n"
                    "engine runtime and recompile your data. That should fix the issue.\n"
                    "\n"
                    "As a last resort, if you can't find any other way of getting rid of this error, you can\n"
                    "try to delete your data folder and recompile everything from scratch.",
                    "unit",
                    10965745i64);
                report_assert_failure(
                    20,
                    "D:\\BuildAgent\\work\\a\\git_work\\runtime\\foundation/resource/resource_version.h",
                    0i64,
                    v4);
            }
            StrongPointerVectorSerializer<MeshGeometry>::serialize<InputArchive>(&v10, v2);
            StrongPointerVectorSerializer<SkinData>::serialize<InputArchive>(&v11, v2);
            raw_array_serialize<InputArchive, char>(v2, &v3->_simple_animation);
            if (!v3->_simple_animation_groups._is_sorted)
            {
                v5 = eprintf("SortMap not sorted");
                report_assert_failure(
                    392,
                    "d:\\buildagent\\work\\a\\git_work\\runtime\\foundation\\collection\\sort_map.inl",
                    "_is_sorted",
                    v5);
            }
            Vector<Pair<IdString32, Vector<int>, 0, 1>>::serialize<InputArchive>(
                &v3->_simple_animation_groups._data,
                v2);
            v3->_simple_animation_groups._is_sorted = 1;
            SceneGraph::serialize<InputArchive>(&v3->_scene_graph, v2);
            StrongPointerVectorSerializer<MeshObject>::serialize<InputArchive>(&v12, v2);
            StrongPointerVectorSerializer<ActorResource>::serialize<InputArchive>(&v13, v2);
            StrongPointerVectorSerializer<Camera>::serialize<InputArchive>(&v14, v2);
            StrongPointerVectorSerializer<Light>::serialize<InputArchive>(&v15, v2);
            StrongPointerVectorSerializer<LODObjectData>::serialize<InputArchive>(&v16, v2);
            StrongPointerVectorSerializer<TerrainData>::serialize<InputArchive>(&v17, v2);
            Vector<JointDesc>::serialize<InputArchive>(&v3->_joints, v2);
            Vector<MoverDesc>::serialize<InputArchive>(&v3->_movers, v2);
            if (!v3->_script_events._is_sorted)
            {
                v6 = eprintf("SortMap not sorted");
                report_assert_failure(
                    392,
                    "d:\\buildagent\\work\\a\\git_work\\runtime\\foundation\\collection\\sort_map.inl",
                    "_is_sorted",
                    v6);
            }
            Vector<Pair<IdString32, ScriptMethod, 0, 1>>::serialize<InputArchive>(
                &v3->_script_events._data,
                v2);
            v3->_script_events._is_sorted = 1;
            InputArchive::read(v2, &v3->_has_animation_blender_bones, 1u);
            DynamicString::serialize<InputArchive>(&v3->_animation_state_machine, v2);
            raw_array_serialize<InputArchive, char>(v2, &v3->_dynamic_data._data);
            if (!v3->_visibility_groups._is_sorted)
            {
                v7 = eprintf("SortMap not sorted");
                report_assert_failure(
                    392,
                    "d:\\buildagent\\work\\a\\git_work\\runtime\\foundation\\collection\\sort_map.inl",
                    "_is_sorted",
                    v7);
            }
            Vector<Pair<IdString32, Vector<unsigned int>, 0, 1>>::serialize<InputArchive>(
                &v3->_visibility_groups._data,
                v2);
            v3->_visibility_groups._is_sorted = 1;
            raw_array_serialize<InputArchive, char>(v2, &v3->_flow);
            raw_array_serialize<InputArchive, char>(v2, &v3->_flow_dynamic_data);
            raw_array_serialize<InputArchive, char>(v2, &v3->_mesh_geometry_triangle_finder);
            v8 = &v3->_physics_scene_data._size;
            raw_array_serialize<InputArchive, char>(v2, &v3->_physics_scene_data);
            raw_array_serialize<InputArchive, char>(v2, &v3->_physics_scene_data_64bit);
            InputArchive::read(v2, &v3->_default_material_resource, 8u);
            if (!v3->_materials._is_sorted)
            {
                v9 = eprintf("SortMap not sorted");
                report_assert_failure(
                    392,
                    "d:\\buildagent\\work\\a\\git_work\\runtime\\foundation\\collection\\sort_map.inl",
                    "_is_sorted",
                    v9);
            }
            Vector<Pair<IdString32, IdString64, 0, 0>>::serialize<InputArchive>(
                &v3->_materials._data,
                v2);
            v3->_materials._is_sorted = 1;
            raw_array_serialize<InputArchive, char>(v2, &v3->_apex_data);
            StrongPointerVectorSerializer<VehicleResource>::serialize<InputArchive>(&v18, v2);
            InputArchive::read(v2, &v3->_skeleton_name, 8u);
            if (v3->_physics_scene_data._capacity)
            {
                if (*v8)
                    *v8 = 0;
                ((void(__fastcall*)(Allocator*, char*))v3->_physics_scene_data._allocator->vfptr->deallocate)(
                    v3->_physics_scene_data._allocator,
                    v3->_physics_scene_data._data);
                v3->_physics_scene_data._data = 0i64;
                v3->_physics_scene_data._capacity = 0;
            }
        }*/
    };
}
