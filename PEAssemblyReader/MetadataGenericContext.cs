﻿// --------------------------------------------------------------------------------------------------------------------
// <copyright file="MetadataGenericContext.cs" company="">
//   
// </copyright>
// <summary>
//   
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace PEAssemblyReader
{
    using System.Collections.Generic;
    using System.Diagnostics;

    /// <summary>
    /// </summary>
    public class MetadataGenericContext : IGenericContext
    {
        /// <summary>
        /// </summary>
        public MetadataGenericContext()
            : this(new SortedDictionary<IType, IType>())
        {
        }

        public MetadataGenericContext(IDictionary<IType, IType> map)
        {
            this.Map = map;
        }

        /// <summary>
        /// </summary>
        /// <param name="type">
        /// </param>
        public MetadataGenericContext(IType type, bool allowToUseDefinitionAsSpecialization = false)
            : this()
        {
            this.Init(type, allowToUseDefinitionAsSpecialization);           
            if (this.TypeSpecialization != null)
            {
                this.TypeSpecialization.GenericMap(this.Map);
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="method">
        /// </param>
        public MetadataGenericContext(IMethod method, bool allowToUseDefinitionAsSpecialization = false)
            : this(method.DeclaringType, allowToUseDefinitionAsSpecialization)
        {
            this.Init(method, allowToUseDefinitionAsSpecialization);
            if (this.MethodSpecialization != null)
            {
                MethodSpecialization.GenericMap(this.Map);
            }
        }

        /// <summary>
        /// </summary>
        public bool IsEmpty
        {
            get
            {
                return this.Map.Count == 0 && this.TypeDefinition == null && this.TypeSpecialization == null && this.MethodDefinition == null && this.MethodSpecialization == null;
            }
        }

        /// <summary>
        /// </summary>
        public IDictionary<IType, IType> Map { get; private set; }

        /// <summary>
        /// </summary>
        public IMethod MethodDefinition { get; set; }

        /// <summary>
        /// </summary>
        public IMethod MethodSpecialization { get; set; }

        /// <summary>
        /// </summary>
        public IType TypeDefinition { get; set; }

        /// <summary>
        /// </summary>
        public IType TypeSpecialization { get; set; }

        public static IGenericContext DiscoverFrom(IMethod method, bool allowToUseDefinitionAsSpecialization = false)
        {
            if (method.IsGenericMethod || method.IsGenericMethodDefinition)
            {
                return new MetadataGenericContext(method, allowToUseDefinitionAsSpecialization);
            }

            var declType = method.DeclaringType;
            while (declType != null)
            {
                if (declType.IsGenericType || declType.IsGenericTypeDefinition)
                {
                    return new MetadataGenericContext(declType, allowToUseDefinitionAsSpecialization);
                }

                if (declType.IsNested)
                {
                    declType = declType.DeclaringType;
                    continue;
                }

                break;
            }

            return null;
        }

        public static IGenericContext CreateMap(IMethod definitionMethod, IMethod specializationMethod)
        {
            var context = new MetadataGenericContext();
            context.Map.GenericMap(definitionMethod.GetGenericParameters(), specializationMethod.GetGenericArguments());
            context.Map.GenericMap(definitionMethod.DeclaringType.GenericTypeParameters, specializationMethod.DeclaringType.GenericTypeArguments);
            return context;
        }

        public IType ResolveTypeParameter(IType typeParameter)
        {
            IType resolved = null;
            if (Map.TryGetValue(typeParameter, out resolved))
            {
                return resolved;
            }

            return typeParameter;
        }

        /// <summary>
        /// </summary>
        /// <param name="type">
        /// </param>
        private void Init(IType type, bool allowToUseDefinitionAsSpecialization = false)
        {
            if (type.IsGenericTypeDefinition)
            {
                this.TypeDefinition = type;
                if (allowToUseDefinitionAsSpecialization)
                {
                    this.TypeSpecialization = type;
                }
            }

            if (type.IsGenericType)
            {
                this.TypeSpecialization = type;
                if (this.TypeDefinition == null)
                {
                    this.TypeDefinition = type.GetTypeDefinition();
                }
            }
        }

        /// <summary>
        /// </summary>
        /// <param name="method">
        /// </param>
        private void Init(IMethod method, bool allowToUseDefinitionAsSpecialization = false)
        {
            if (method.IsGenericMethodDefinition)
            {
                this.MethodDefinition = method;
                if (allowToUseDefinitionAsSpecialization)
                {
                    this.MethodSpecialization = method;
                }
            }

            if (method.IsGenericMethod)
            {
                this.MethodSpecialization = method;
                if (this.MethodDefinition == null)
                {
                    this.MethodDefinition = method.GetMethodDefinition();
                }
            }
        }
    }
}